

#include <iostream>

using namespace std;

struct Node
{
    string data, meaning;
    Node *left;
    Node *right;
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
        
        Node* createNode(string da, string mea)
        {
            Node *newNode = new Node();
            if (!newNode) 
            {
                cout << "Memory error\n";
                return NULL;
            }
            newNode->data = da;
            newNode->meaning = mea;
            newNode->left = newNode->right = NULL;
            return newNode;
        }

        Node* insertNode(Node* root, string dat, string mean)
        {
            if (root == NULL) 
            {
                root = createNode(dat,mean);
                return root;
            }

            if (dat < root->data)
                root->left = insertNode(root->left, dat, mean);
            else
                root->right = insertNode(root->right, dat, mean);

            return root;
        }

        void insert(string data, string meaning)
        {
            root = insertNode(root, data, meaning);
        }
        
        void inorder(Node* temp)
        {
            if (temp == NULL)
                return;

            inorder(temp->left);
            cout <<"Keyword : "<<temp->data<<" Meaning : " <<temp->meaning<<"\n";
            inorder(temp->right);
        }
        
        void display()
        {
            inorder(root);
            cout<<"\n";
        }
		
		Node* search_data(string d, Node* t)
		{
			Node* temp ;
			temp = t;
			
			while(temp != NULL)
			{
				if(temp->data == d)
				{
					return temp;
				}
				
				if(d>temp->data)
				{
					return search_data(d,temp->right);
				}
				else
				{
					return search_data(d, temp->left);
				}
			}
			return NULL;
		}
		
		void Update(string key, string new_meaning)
		{
			Node* p = search_data(key,root);
			if(p == NULL)
			{
				return;
			}
			else
			{
				p->meaning = new_meaning;
				cout<<"Updated"<<endl;
			}
		}
		
		Node* del(Node* root, string d)
		{
		    if (root == NULL)
		        return root;
		
		    if (d < root->data)
			{
				root->left = del(root->left, d);
			}
		    else if (d > root->data)
			{
				root->right = del(root->right, d);
			}
		    else
		    {
		        if (root->left == NULL)
		        {
		            Node* temp = root->right;
		            delete root;
		            return temp;
		        }
		        else if (root->right == NULL)
		        {
		            Node* temp = root->left;
		            delete root;
		            return temp;
		        }
		
		        Node* temp = root->right;
		        while (temp->left != NULL)
				{
					temp = temp->left;
				}
		
		        root->data = temp->data;
		        root->meaning = temp->meaning;
		
		        root->right = del(root->right, temp->data);
		    }
		    return root;
		}
		
		void Delete(string data)
		{
		    root = del(root, data);
		    if (root == NULL)
			{
				cout << "The data to be deleted is not present." << endl;
			}
		    else
			{
				cout << "Deleted " << data << " successfully." << endl;
			}
		}

				
};

int main()
{
    Tree a;
    int flag = 0;
    cout<<"<<----------------OPERATIONS-------------->>";
    do
    {
        int choice;
        cout << "\n1.Insert\n2.Display\n3.Update\n4.Delete\n5.Exit\nChoice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                string d;
                cout << "Data : ";
                cin >> d;

                string m;
                cout << "Meaning : ";
                cin >> m;
                

                a.insert(d, m);

                cout << "\n";
                break;
            }
            case 2:
            {
                a.display();
                cout << "\n";
                break;
            }
            case 3:
            {
                string key;
                cout << "Data to be update: ";
                cin >> key;

                string new_meaning;
                cout << "New Meaning: ";
                cin >> new_meaning;

                a.Update(key, new_meaning);
                cout << "\n";
                break;
            }
            case 4:
            {
                string data;
                cout << "Data to be deleted : ";
                cin >> data;

                a.Delete(data);
                cout << "\n";
                break;
            }
            case 5:
            {
                flag = 1;
                cout<<"\n";
                break;
            }
            default:
            {
                cout << "Please Enter a valid number" << endl;
                cout << "\n";
                break;
            }
        }

    } while (flag != 1);

    return 0;
}



 


