#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Student {
    struct Record {
        int roll;
        char name[50];
        char div;
        char address[100];
    } record;

public:
    void read();
    void create();
    void display();
    int search(int);
    void deleteRecord();
    void sortRecords();
    void createIndex();
};

void Student::read() {
    cout << "\nEnter Roll No of Student: ";
    cin >> record.roll;
    cout << "Enter Name of Student: ";
    cin >> record.name;
    cout << "Enter Division of Student: ";
    cin >> record.div;
    cout << "Enter Address of Student: ";
    cin>>record.address;
}

void Student::create() {
    char ans;
    ofstream fout;
    fout.open("students.dat", ios::out | ios::binary | ios::app); // Open in append mode
    do {
        this->read();
        fout.write(reinterpret_cast<char *>(&record), sizeof(Record));
        cout << "\nDo You Want to Add More Records (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    fout.close();

    sortRecords();
    createIndex();
}

void Student::sortRecords() {
    ifstream fin("students.dat", ios::in | ios::binary);
    ofstream fout("temp.dat", ios::out | ios::binary); // Temporary file for sorting
    Record temp;

    int count = 0;
    while (fin.read(reinterpret_cast<char *>(&record), sizeof(Record))) {
        count++;
    }
    fin.clear(); // Clear end-of-file flag
    fin.seekg(0, ios::beg); // Reset file pointer to the beginning

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            fin.read(reinterpret_cast<char *>(&record), sizeof(Record));
            Record nextRecord;
            fin.read(reinterpret_cast<char *>(&nextRecord), sizeof(Record));
            if (record.roll > nextRecord.roll) {
                temp = record;
                record = nextRecord;
                nextRecord = temp;
            }
            fout.write(reinterpret_cast<char *>(&record), sizeof(Record));
            fout.write(reinterpret_cast<char *>(&nextRecord), sizeof(Record));
        }
    }
    fin.close();
    fout.close();

    // Replace students.dat with sorted temp.dat
    remove("students.dat");
    rename("temp.dat", "students.dat");
}

void Student::createIndex() {
    ifstream fin("students.dat", ios::in | ios::binary);
    ofstream indexFile("index.dat", ios::out | ios::binary);
    int pos = 0;
    while (fin.read(reinterpret_cast<char *>(&record), sizeof(Record))) {
        indexFile.write(reinterpret_cast<char *>(&pos), sizeof(int));
        pos = fin.tellg();
    }
    fin.close();
    indexFile.close();
}

void Student::display() {
    ifstream fin("students.dat", ios::in | ios::binary);
    cout << "\nStudent Records:\n";
    while (fin.read(reinterpret_cast<char *>(&record), sizeof(Record))) {
        cout << "Roll No: " << record.roll << endl;
        cout << "Name: " << record.name << endl;
        cout << "Division: " << record.div << endl;
        cout << "Address: " << record.address << endl << endl;
    }
    fin.close();
}

int Student::search(int roll) {
    ifstream indexFile("index.dat", ios::in | ios::binary);
    int indexPos;
    while (indexFile.read(reinterpret_cast<char *>(&indexPos), sizeof(int))) {
        ifstream dataFile("students.dat", ios::in | ios::binary);
        dataFile.seekg(indexPos);
        dataFile.read(reinterpret_cast<char *>(&record), sizeof(Record));
        if (record.roll == roll) {
            cout << "\nRecord Found:\n";
            cout << "Roll No: " << record.roll << endl;
            cout << "Name: " << record.name << endl;
            cout << "Division: " << record.div << endl;
            cout << "Address: " << record.address << endl;
            dataFile.close();
            indexFile.close();
            return 1;
        }
        dataFile.close();
    }
    indexFile.close();
    return 0;
}

void Student::deleteRecord() {
    int roll;
    cout << "\nEnter Roll No to delete: ";
    cin >> roll;
    ifstream indexFile("index.dat", ios::in | ios::binary);
    ofstream tempFile("temp.dat", ios::out | ios::binary); // Temporary file for storing non-deleted records
    int indexPos;
    bool found = false;
    while (indexFile.read(reinterpret_cast<char *>(&indexPos), sizeof(int))) {
        ifstream dataFile("students.dat", ios::in | ios::binary);
        dataFile.seekg(indexPos);
        dataFile.read(reinterpret_cast<char *>(&record), sizeof(Record));
        if (record.roll == roll) {
            cout << "\nRecord Found and Deleted:\n";
            cout << "Roll No: " << record.roll << endl;
            cout << "Name: " << record.name << endl;
            cout << "Division: " << record.div << endl;
            cout << "Address: " << record.address << endl;
            found = true;
        } else {
            // Write non-deleted records to temporary file
            tempFile.write(reinterpret_cast<char *>(&record), sizeof(Record));
        }
        dataFile.close();
    }
    indexFile.close();
    tempFile.close();

    if (!found) {
        cout << "\nRecord Not Found";
        return;
    }

    // Replace students.dat with temp.dat
    remove("students.dat");
    rename("temp.dat", "students.dat");

    // Recreate index file
    createIndex();
}

int main() {
    Student obj;
    int choice;
    char ans;
    do {
        cout << "\n***** Student Information *****";
        cout << "\n1. Create\n2. Display\n3. Delete\n4. Search\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                obj.create();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                obj.deleteRecord();
                break;
            case 4:
                int roll;
                cout << "\nEnter Roll No to search: ";
                cin >> roll;
                if (!obj.search(roll))
                    cout << "\nRecord Not Found\n";
                break;
            case 5:
                break;
            default:
                cout << "\nInvalid Choice";
        }
        cout << "\nDo You Want to Continue (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 0;
}

