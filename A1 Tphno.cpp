#include <iostream>
#include <fstream>
#define max 10

using namespace std;

struct node
{
	int rollno;
	node* next;
};

class Openhash
{
	private:
		node* hashtable[max];
		
	public:
		Openhash()
		{
			for(int i = 0; i<max; i++)
			{
				hashtable[i] = NULL;
			}
		}
		
		void get_data(int roll)
		{
		    node* new_node = new node;
		    new_node->rollno = roll;
		    new_node->next = NULL;
		
		    int loc = roll % max;
		    if (hashtable[loc] == NULL)
		    {
		        hashtable[loc] = new_node;
		    }
		    else
		    {
		        node* pointer = hashtable[loc];
		        while (pointer->next != NULL)
		        {
		            pointer = pointer->next;
		        }
		        pointer->next = new_node;
		    }
		}
		
		void remove(int roll)
		{
		    int loc = roll % max;
		    node* current = hashtable[loc];
		    node* previous = NULL;
		
		    while (current != NULL)
		    {
		        if (current->rollno == roll)
		        {
		            if (previous == NULL)
		            {
		                hashtable[loc] = current->next;
		            }
		            else
		            {
		                previous->next = current->next;
		            }
		            
		            delete current;
		        }
		
		        previous = current;
		        current = current->next;
		    }
		    
		}
		
		void search(int roll)
		{
		    int loc = roll%max;
		    node* pointer = hashtable[loc];
		
		    int i = 1;
		
		    while (pointer != NULL)
		    {
		        if (pointer->rollno == roll)
		        {
		            cout << "The " << roll << " is at " << i << "th index & " << loc << "th location of the hashtable"<<endl;
		            cout<<"And the number of comparisons required are "<<i;
		            return;
		        }
		        
		        pointer = pointer->next;
		        i++;
		    }
		    cout << "The required data is not present, Sorry"<<endl;
		    cout<<"And the number of comparisons required are "<<i;
		}


		void display()
		{
		    for (int i = 0; i < max; i++)
		    {
		        node* pointer = hashtable[i];
		        while (pointer != NULL)
		        {
		            cout << pointer->rollno << "->";
		            pointer = pointer->next;
		        }
		        cout << "NULL\n";
		    }
		}

};

class Linear_probing_without_chaining
{
	private:
	    int hashtable[max];
	    int flagtable[max];
	
	public:
	    Linear_probing_without_chaining()
	    {
	        for (int i = 0; i < max; i++)
	        {
	            flagtable[i] = 0;
	        }
	    }
	
	    void Insert(int a)
	    {
	        int loc = a % max; 
	        int i = 1;
	        
	        while(flagtable[loc] == 1 && i<max)
			{
				loc = (loc + 1)%max;
				i++;
			}
			
			if(flagtable[loc] == 0)
			{
				hashtable[loc] = a;
				flagtable[loc] = 1;
			}
	    }
	
	    void display()
	    {
	        bool printed = false;
	        for (int i = 0; i < max; i++)
	        {
	            if (flagtable[i] == 1)
	            {
	                cout << hashtable[i] << " -> ";
	                printed = true; 
	            }
	        }
	        if (!printed)
	        {
	            cout << "Empty";
	        }
	        cout << "End";
	    }
	    
	    void Search(int key)
		{
			for(int i =0; i<max;i++)
			{
				if(flagtable[i] ==1 && hashtable[i] == key)
				{
					cout<<"The element is found at "<<i<<"th location";
					return;
				}
			}
			cout<<"Element not found, Sorry";
		}
};

int main()
{
	int choice;
	int flag = 0;
	Openhash a;
	Linear_probing_without_chaining z;
	
	do
	{
		cout<<"1.Open Hashing\n2.Closed Hashing\n3.Close\nChoice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				int flag1;
				do
				{
					int choice1;
					cout<<"1.Insert\n2.Display\n3.Search\n4.Remove\n5.Exit\nYour Choice : ";
					cin>>choice1;
					
					switch(choice1)
					{
						case 1:
							int b;
							cout<<"What is to be inserted : ";
							cin>>b;
							a.get_data(b);
							break;
							
						case 2:
							a.display();
							break;
							
						case 3:
							int c;
							cout<<"What is to be searched : ";
							cin>>c;
							a.search(c);
							break;
							
						case 4:
							int f;
							cout<<"Which element is to be removed : ";
							cin>>f;
							a.remove(f);
							break;
							
						case 5:
							flag1 = 1;
							break;
						
						default:
							cout<<"Please Enter Valid choice"<<endl;
							break;
					}
					cout<<endl;
					
				}while(flag1 != 1);
				break;
				
			case 2:
				int flag2;
				do
				{
					int choice2;
					cout<<"1.Insert\n2.Display\n3.Search\n4.Remove\n5.Exit\nYour Choice : ";
					cin>>choice2;
					
					switch(choice2)
					{
						case 1:
							int b;
							cout<<"What is to be inserted : ";
							cin>>b;
							z.Insert(b);
							break;
							
						case 2:
							z.display();
							break;
							
						case 3:
							int c;
							cout<<"What is to be searched : ";
							cin>>c;
							z.Search(c);
							break;
							
						case 5:
							flag2 = 1;
							break;
						
						default:
							cout<<"Please Enter Valid choice"<<endl;
							break;
					}
					cout<<endl;
					
				}while(flag2 != 1);
				break;	
			
			case 3:
				flag = 1;
				break;
				
			default:
				cout<<"Please Enter Valide Choice"<<endl;
				break;
		}
	}while(flag != 1);
	
	return 0;
}
