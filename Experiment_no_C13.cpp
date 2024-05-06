#include <iostream>
#include <fstream>
#define max 10

using namespace std;

struct H_Node {
    int data;
    H_Node* next;
};

class hashtable {
private:
    H_Node* a[max];

public:
    hashtable() {
        for (int i = 0; i < max; i++) {
            a[i] = NULL;
        }
    }

    void create(int data, int position) {
        H_Node* new_node = new H_Node;
        new_node->data = data;
        new_node->next = NULL;
        int loc = position;

        if (a[loc] != NULL) {
            H_Node* pointer = a[loc];

            while (pointer->next != NULL) {
                pointer = pointer->next;
            }

            pointer->next = new_node;
            return;
        } else {
            a[loc] = new_node;
            return;
        }
    }
};

class Graph {
private:
    int m, n;
    int* matrix;
    hashtable hash; // Integrate hashtable
    string* vertexNames; // Array to store vertex names

public:
    Graph() {
        cout << "Number of vertices, please => ";
        cin >> m;
        n = m; // Fixed assignment error here

        matrix = new int[m * n];
        vertexNames = new string[m]; // Allocate memory for vertex names
    }

    ~Graph() { // Destructor to free allocated memory
        delete[] matrix;
        delete[] vertexNames;
    }

    void M_creating() 
	{
    	for(int i= 0; i<m; i++)
		{
			string name;
			cout<<"Name of Vertice "<< i <<" => ";
			cin>>name;
			
			vertexNames[i] = name;
		}
		
        for (int i = 0; i < m; i++) 
		{

            for (int j = 0; j < n; j++) 
			{
                if (i == j) 
				{
                    char choice;
                    cout << "Is there a self loop on vertex " << vertexNames[i] << "? (Y/N): ";
                    cin >> choice;

                    switch (choice) 
					{
                        case 'Y':
                        case 'y':
                            matrix[i * n + j] = 1;
                            break;

                        case 'N':
                        case 'n':
                            matrix[i * n + j] = 0;
                            break;

                        default:
                            cout << "Enter a valid choice, please" << endl;
                            j--; // To re-ask the same question for invalid input
                            break;
                    }
                } 
				else 
				{
                    char choice;
                    cout << "Is there an edge between " << vertexNames[i] << " and " << vertexNames[j] << "? (Y/N): ";
                    cin >> choice;

                    switch (choice) 
					{
                        case 'Y':
                        case 'y':
                            matrix[i * n + j] = 1;
                            break;

                        case 'N':
                    	case 'n':
                            matrix[i * n + j] = 0;
                            break;

                        default:
                            cout << "Enter a valid choice, please" << endl;
                            j--; // To re-ask the same question for invalid input
                            break;
                    }
                }
            }
        }
    }

	void printMatrix() 
	{
	    cout << "The adjacency matrix is as follows:" << endl;
	    // Print column labels
	    cout << "   ";
	    for (int j = 0; j < n; ++j) 
		{
	        cout << vertexNames[j] << " ";
	    }
	    cout << endl;
	
	    // Print matrix rows
	    for (int i = 0; i < m; ++i) 
		{
	        cout << vertexNames[i] << " ";
	        for (int j = 0; j < n; ++j) 
			{
	            cout << matrix[i * n + j] << " ";
	        }
	        cout << endl;
	    }
	}

	
    void printVertices() 
	{
        cout << "Vertices of the graph:" << endl;
        for (int i = 0; i < m; ++i) 
		{
            cout << i << ": " << vertexNames[i] << endl;
        }
    }

    // Depth First Search (DFS)
    void DFS(int v, bool visited[]) 
	{
        visited[v] = true;
        cout << vertexNames[v] << " ";

        for (int i = 0; i < n; i++) 
		{
            if (matrix[v * n + i] && !visited[i]) 
			{
                DFS(i, visited);
            }
        }
    }

    // Breadth First Search (BFS)
    void BFS(int v, bool visited[]) 
	{
	    for (int i = 0; i < n; i++)
	        visited[i] = false;
	
	    visited[v] = true;
	    H_Node* queue = new H_Node;
	    queue->data = v;
	    queue->next = NULL;
	
	    while (queue != NULL) {
	        v = queue->data;
	        cout << vertexNames[v] << " ";
	
	        H_Node* temp = queue;
	        queue = queue->next;
	        delete temp;
	
	        for (int i = 0; i < n; i++) {
	            if (matrix[v * n + i] && !visited[i]) {
	                visited[i] = true;
	
	                H_Node* newNode = new H_Node;
	                newNode->data = i;
	                newNode->next = NULL;
	
	                if (queue == NULL)
	                    queue = newNode;
	                else {
	                    H_Node* pointer = queue;
	                    while (pointer->next != NULL)
	                        pointer = pointer->next;
	                    pointer->next = newNode;
	                }
	            }
	        }
	    }
	}

    
    int getNumVertices()
	{
		return m;
	}
};

int main() 
{
    Graph g;
    g.M_creating();

    g.printMatrix();
    g.printVertices();
    
    cout<<endl;
    int flag = 0;
    int choice;
    
    bool* visited = new bool[g.getNumVertices()];
    
    do {
        cout << "1.DFS\n2.BFS\n3.Exit\n";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "DFS traversal: ";
                for (int i = 0; i < g.getNumVertices(); i++)
                    visited[i] = false;
                g.DFS(0, visited);
                cout << endl;
                break;
                
            case 2:
                cout << "BFS traversal: ";
                for(int i = 0; i<g.getNumVertices(); i++)
				{
					visited[i] = false;
				}
                g.BFS(0,visited);
                cout << endl;
                break;
                
            case 3:
                flag = 1;
                cout << endl;
                break;
                
            default:
                cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
                break;
        }
    } while (flag != 1);

    return 0;
}



