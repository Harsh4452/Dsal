#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
typedef struct stud
	{
		int roll;
		char name[10];
		char div;
		char add[10];
		
	};
class student
  {
  	public:
	
	 stud rec;
	
	  void insert(stud rec1);
	  void display();
	  int search();
	  void Delete();
	  stud getdata();
	  
  };
  stud student::getdata()
  {
  	
  	 cout<<"\n Enter roll no: ";
  	 cin>>rec.roll;
  	 cout<<"\n Enter name: ";
  	 cin>>rec.name;
  	 cout<<"\n Enter div: ";
  	 cin>>rec.div;
  	 cout<<"\n Enter add: ";
  	 cin>>rec.add;
  	 
  	 return rec;
  	 
  }
void student::insert(stud rec1)
  {
	stud rec;
	int  i,n,k;
	
	fstream f;
	f.open("stud.dat",ios::out|ios::in|ios::binary); 
	//rec1.status=0; 
	f.seekg(0,ios::end);
	
	n = (f.tellg()/sizeof(stud));
	
	
	if(n == 0)
	{
		f.write((char *)&rec1,sizeof(stud))<<flush;
		
        f.close();
        return ; 
	}
	i=n-1;
	
	
	while(i>=0)
	{
		
		f.seekg(i*sizeof(stud),ios::beg);
		f.read((char *)&rec,sizeof(stud));
		
		
		
		if(rec.roll>rec1.roll)
		{
			f.seekp(i+1*sizeof(stud),ios::beg);
			f.write((char *)&rec,sizeof(stud))<<flush;
		}
		else
		{
			break;
		}
		i--;
	}
	
	i++;
	f.seekp(i*sizeof(stud),ios::beg);
	f.write((char *)&rec1,sizeof(stud))<<flush;
	f.close();
	
	}
void student::display()
  {
     stud rec;
     int i=1 , n;
     fstream f;
     f.open("stud.dat",ios::out|ios::in|ios::binary);
     f.seekg(0,ios::end);
     n=(f.tellg()/sizeof(stud));
     f.seekg(0,ios::beg);
     for(i=1 ; i<=n ; i++)
     {
     	f.read((char *)&rec,sizeof(stud));
     	cout<<"\n"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
	 }
	 f.close();
  }
  
int student::search()
  {
	int r,i=0;
	ifstream fin;
	fin.open("stud.dat",ios::in|ios::binary);
	fin.seekg(0,ios::beg);
	cout<<"\n\tEnter a Roll No: ";
	cin>>r;
	while(fin.read((char *)&rec,sizeof(stud)))
	  {
		if(rec.roll==r)
		  {
			cout<<"\n\tRecord Found...\n";
			cout<<"\n\tRoll\tName\tDiv\tAddress";
			cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
			return i+1;
		  }
		i++;
	  }
	fin.close();
	return 0;
  }
  
void student::Delete()
  {
    int roll;
    cout <<"\nEnter Roll No to delete: ";
    cin >>roll;
    ifstream fin;
    ofstream fout;
	fin.open("stud.dat", ios::in|ios::binary); 
	fout.open("temp.dat", ios::out|ios::binary); // Temporary file for storing non-deleted records
    while (fin.read((char*)&rec, sizeof(stud))) {
        if (rec.roll != roll) {
            fout.write((char*)&rec, sizeof(stud));
        }
    }
    fin.close();
    fout.close();

    // Replace students.dat with temp.dat
    remove("stud.dat");
    rename("temp.dat", "stud.dat");
    cout<<"\n Record Deleted Successfully ";
  }
	
int main()
  {
	student obj;
	int ch,key;
	char ans;
	stud record;
	
	ofstream fout;
	fout.open("stud.dat",ios::out|ios::binary); 
	fout.close();
	fout.open("temp.dat",ios::out|ios::binary); 
	fout.close();
	
	do
	  {
	  	cout<<"\n";
		cout<<"\n\t** Student Information **";
		cout<<"\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4. Search\n\t5. Exit";
		cout<<"\n\t..... Enter Your Choice: ";
		cin>>ch;
		switch(ch)
		  {
		  	
			case 1: 
			 record = obj.getdata();
			 
			obj.insert(record);
				break;
			case 2:	obj.display();
				break;
			case 3: obj.Delete();
				break;
			case 4: key=obj.search();
				if(key==0)
				  cout<<"\n\tRecord Not Found...\n";
				break;
			case 5:
				cout<<"\n Program Ended Successfully ";
				break;
		  }
		
	  }while(ch!=5);
return 1;
  }
