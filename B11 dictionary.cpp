#include <iostream>
#include <fstream>

using namespace std;

class Tree
{
	private:
		struct Node
		{
			string data, meaning;
			Node* Left;
			Node* Right;
		};
		
		Node* root;
		
	public:
		Tree()
		{
			root = NULL;
		}
		
		Node* New_insert(Node* temp, string data1, string meaning1)
		{
			if (temp == NULL)
			{
				Node* new_Node = new Node;
				new_Node->data = data1;
				new_Node->meaning = meaning1;
				new_Node->Left = new_Node->Right = NULL;
				return new_Node;
			}
			
			if (data1 < temp->data)
			{
				temp->Left = New_insert(temp->Left, data1, meaning1);
			}
			else if (data1 > temp->data)
			{
				temp->Right = New_insert(temp->Right, data1, meaning1);
			}
			return temp;
		}
		
		void insert(string data, string meaning)
		{
			root = New_insert(root, data, meaning);
		}
		
		void inorder(Node* temp)
		{
			if(temp == NULL)
			{
				return;
			}
			
			inorder(temp->Left);
			cout << "Data : " << temp->data << "\tMeaning : " << temp->meaning << endl;
			inorder(temp->Right);
		}
		
		
		void display()
		{
			inorder(root);
		}
		
		Node* T_search(Node* temp, string data)
		{
			Node* temporary = NULL;
			
			if(temp == NULL)
			{
				return NULL;
			}
			
			if(temp->data > data)
			{
				temporary = T_search(temp->Left, data);
			}
			else if(temp->data < data)
			{
				temporary = T_search(temp->Right, data);
			}
			else
			{
				return temp;
			}
			return temporary;
		}
		
		void search(string d)
		{
			Node* search_data = T_search(root,d);
			if(search_data == NULL)
			{
				cout<<"not found"<<endl;
				return;
			}
			else
			{
				cout<<d<<" found"<<endl;
			}
			return;
		}
		
		void Update(string key, string new_meaning)
		{
			Node* search_data = T_search(root,key);
			if(search_data == NULL)
			{
				cout<<"Not found"<<endl;
			}
			else
			{
				search_data->meaning = new_meaning;
			}
			return;
		}
		
		Node* del(Node* temp,string d_data)
		{
			Node* D_Node = T_search(temp, d_data);
			if(D_Node == NULL)
			{
				return NULL;
			}
			else
			{
				if(D_Node->Left == NULL && D_Node->Right == NULL)
				{
					Node* y = D_Node;
					delete D_Node;
					cout<<"done";
					return y;
				}
				else if(D_Node->Left == NULL)
				{
					Node* y = D_Node->Right;
					delete D_Node;
					cout<<"Done";
					return y;
				}
				else if(D_Node->Right == NULL)
				{
					Node* y = D_Node->Left;
					delete D_Node;
					cout<<"Done";
					return y;
				}
				
				Node* temp = D_Node->Right;
				while(temp->Right != NULL)
				{
					temp = temp->Right;
				}
				
				D_Node->data = temp->data;
				D_Node->meaning = temp->meaning;
				
				D_Node->Right = del(D_Node->Right, temp->data);
			}
		}
		
		void Delete(string D_Data)
		{
			Node* key = this->del(root, D_Data);
			if(key == NULL)
			{
				cout<<"Not found";
				return;
			}
			else
			{
				cout<<"Deleted";
				return;
			}
		}
};



int main()
{
	Tree a;
	a.insert("yello", "yue");
	a.insert("kielo", "ioer");
	a.insert("ur", "sdfs");
	a.display();
	cout<<"\n";
	a.Update("yello","bello");
	a.display();
	a.Delete("yello");
	cout<<"\n";
	a.display();
	return 0;
}

