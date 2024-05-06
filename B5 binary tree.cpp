#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Stack
{
    private: 
        Node **a;
        int top, max;
        
    public:
        Stack()
        {
            top = 0;
            a = new Node*[top];
        }
        
        void push(Node* q)
        {
            a[top] = q;
            top++;
            return;
        }
        
        Node* pop()
        {
            if(top == 0)
            {
                cout << "Stack is empty\n";
                return NULL;
            }
            else
            {
                Node* p = a[top - 1];
                top--;
                return p;
            }
        }

        int empty()
        {
            if(top == 0)
            {
                return 1;
            }
            
            return 0;
        }
};

class Tree
{
    private:
        Node *root;
    
    public:
        Tree()
        {
            root = NULL;
        }
        
        Node* createNode()
        {
            Node* new_Node = new Node;
            int x;
            cout<<"Enter the data (-1 for no data)";
            cin>>x;
            if(x == -1)
			{
				return NULL;
			}
			new_Node->data = x;
			cout<<"Enter left Child of : "<<x<<endl;
			new_Node->left = createNode();
			cout<<"Enter the Right Child of : "<<x<<endl;
			new_Node->right = createNode();
			return new_Node;
        }

        void insert()
        {
            root = createNode();
        }
        
        void R_inorder(Node* temp)
        {
            if (temp == NULL)
                return;

            R_inorder(temp->left);
            cout << temp->data << ' ';
            R_inorder(temp->right);
        }
        
        void NR_preorder()
        {
            Stack s;
            Node* t = root;

            while(t != NULL || s.empty() != 1)
            {
                while(t != NULL)
                {
                    cout << t->data << " ";
                    s.push(t);
                    t = t->left;
                }
                t = s.pop();
                t = t->right;
            }
        }

        void display1()
        {
            R_inorder(root);
        }
        
	    void NR_inorder()
	    {
	        Stack s;
	        Node* t = root;
	
	        while(t != NULL || s.empty() != 1)
	        {
	            while(t != NULL)
	            {
	                s.push(t);
	                t = t->left;
	            }
	            t = s.pop();
	            cout << t->data << " ";
	            t = t->right;
	        }
	    }
	
	    void NR_postorder()
	    {
	        Stack s1, s2;
	        Node* t = root;
	        s1.push(t);
	
	        while(s1.empty() != 1)
	        {
	            t = s1.pop();
	            s2.push(t);
	
	            if(t->left)
	                s1.push(t->left);
	            if(t->right)
	                s1.push(t->right);
	        }
	
	        while(s2.empty() != 1)
	        {
	            t = s2.pop();
	            cout << t->data << " ";
	        }
	    }
	
	    void R_preorder(Node* temp)
	    {
	        if (temp == NULL)
	            return;
	
	        cout << temp->data << ' ';
	        R_preorder(temp->left);
	        R_preorder(temp->right);
	    }
	    
	    void display2()
		{
			this->R_preorder(root);
		}
	
	    void R_postorder(Node* temp)
	    {
	        if (temp == NULL)
	            return;
	
	        R_postorder(temp->left);
	        R_postorder(temp->right);
	        cout << temp->data << ' ';
	    }
	    
	    void display3()
		{
			this->R_postorder(root);
		}
};

int main()
{
	cout<<"<-----------------OPERATION---------------->"<<endl;
    Tree a;
    int flag = 0;
    do
	{
		int choice;
		cout<<"1.Insert\n2.Display\n3.Exit\nChoice : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				a.insert();
				break;
				
			case 2:
				cout<<"\n";
				int choice2;
				cout<<"1.Non Recursive Preorder\n2.Non Recursive Inorder\n3.Non Recursive Postorder\n\n4.Recursive Preorder\n5.Recursive Inorder\n6.Recursive Postorder\nChoice : ";
				cin>>choice2;
				
				switch(choice2)
				{
					case 1:
						a.NR_preorder();
						cout<<"\n";
						break;
						
					case 2:
						a.NR_inorder();
						cout<<"\n";
						break;
						
					case 3:
						a.NR_postorder();
						cout<<"\n";
						break;
						
					case 4:
						a.display2();
						cout<<"\n";
						break;
						
					case 5:
						a.display1();
						cout<<"\n";
						break;
						
					case 6:
						a.display3();
						cout<<"\n";
						break;
						
					default:
						cout<<"Please Enter a valid Number";
						cout<<"\n";
						break;
				}
				cout<<"\n";
				break;
				
			case 3:
				flag = 1;
				break;
				
			default:
				cout<<"Please Enter a valid Number";
				cout<<"\n";
				break;
		}
	}while(flag != 1);
}
