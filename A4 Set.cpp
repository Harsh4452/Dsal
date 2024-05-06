#include <iostream>

using namespace std;

template <class T>
class set
{
	private:
		int max;
		T* table;
	public:
		set()
		{
			max = 0;
			table = new T[max];
		}
		
		void Add(T a)
		{
			int f = 0;
			for(int j = 0; j<max; j++)
			{
				if (table[j] == a)
				{
					f = 1;
					break;
				}
			}
			
			if (f == 1)
			{
				return;
			}
			else
			{
				T *temp = new T[max+1];
				for(int i = 0; i<max; i++)
				{
					temp[i] = table[i];
				}
				temp[max] = a;
				delete[] table;
				table = temp;
				max++;
				return;
			}
			
		}
		
		void remove(T a)
		{
			for(int j = 0; j<max;j++)
			{
				if(table[j] == a)
				{
					int u = 0;
					while(u != max)
					{
						table[j+u] = table[j+u+1];
						u++;
					}
					max--;
					return;
				}
			}
			cout<<"The element not found";
		}
		
		void display()
		{
			for(int j  = 0; j<max;j++)
			{
				if(table[j] != 0)
				{
					cout<<table[j]<<"->";
				}
			}
			cout<<"End"<<endl;
		}

		int size()
		{
			return max;
		}

		T element(int q)
		{
			return table[q];
		}

		void Intersection(set <T> &a, set <T> &b)
		{
			set <T> c;
			for(int i = 0; i<a.size(); i++)
			{
				for(int j = 0; j<b.size() ; j++)
				{
					if(a.element(i) == b.element(j))
					{
						c.Add(a.element(i));
						break;
					}
				}
			}
			c.display();
			return;
		}

		void Union(set <T> &a , set <T> &b)
		{
			set <T> c;
			for(int i = 0; i<a.size(); i++)
			{
				for(int j = 0; j<b.size();j++)
				{
					if(a.element(i) != b.element(j))
					{
						c.Add(a.element(i));
						c.Add(b.element(j));
					}
					else
					{
						c.Add(a.element(i));
					}
				}
			}
			c.display();
			return;
		}
		
		void Subset(set<T> &a, set<T> &b)
		{
		    int count = 0;
		
		    for (int i = 0; i < a.size(); i++)
		    {
		        for (int j = 0; j < b.size(); j++)
		        {
		            if (a.element(i) == b.element(j))
		            {
		                count++;
		            }
		        }
		    }
		
		    if (count == a.size() && count == b.size())
		    {
		        cout << "Both sets are subsets of each other" << endl;
		    }
		    else if (count == a.size())
		    {
		        cout << "The set 'a' is a subset of the set 'b'" << endl;
		    }
		    else if (count == b.size())
		    {
		        cout << "The set 'b' is a subset of the set 'a'" << endl;
		    }
		    else
		    {
		        cout << "The given sets are not subsets of each other" << endl;
		    }
		}

		void Difference(set <T> &a , set <T> &b)
		{
			set <T> c;
			int choice;
			cout<<"1.A-B\n2.B-A\nChoice : ";
			cin>>choice;

			switch(choice)
			{
				case 1:
					for (int i = 0; i < a.size(); i++)
					{
						bool flag = false;
						for (int j = 0; j < b.size(); j++)
						{
							if (a.element(i) == b.element(i))
							{
								flag = true;
								break;
							}
						}
						if(flag != true)
						{
							c.Add(a.element(i));
						}
					}
					c.display();
					break;
					
				case 2:
					for (int i = 0; i < b.size(); i++)
					{
						bool flag = false;
						for (int j = 0; j < a.size(); j++)
						{
							if (a.element(i) == b.element(i))
							{
								flag = true;
								break;
							}
						}
						if(flag != true)
						{
							c.Add(b.element(i));
						}
					}
					c.display();
					break;
			}
		}

};


int main()
{
	set <int> a;
	set <int> b;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	int flag4 = 0;

	cout<<"<=========== Adding the Data in the Sets ===========>\n"<<endl;
	do
	{
		int choice1;
		cout<<"1.Add in a\n2.Add in b\n3.Exit\nChoice : ";
		cin>>choice1;
		cout<<endl;
		switch (choice1)
		{
		case 1 :
			do
			{
				int choice2;
				cout<<"1.Add\n2.Display\n3.Remove\n4.Exit\nChoice : ";
				cin>>choice2;
				
				switch (choice2)
				{
				case 1:
					int g;
					cout<<"Add : ";
					cin>>g;
					a.Add(g);
					cout<<endl;
					break;
				
				case 2:
					a.display();
					cout<<endl;
					break;

				case 3:
					int y;
					cout<<"Remove : ";
					cin>>y;
					a.remove(y);
					cout<<endl;
					break;

				case 4:
					flag2 = 1;
					break;
				
				default:
					cout<<"Please Enter a valid Number"<<endl;
					cout<<endl;
					break;
				}
			}while (flag2 != 1);
			cout<<endl;
			break;
		
		case 2:
			do
			{
				int choice3;
				cout<<"1.Add\n2.Display\n3.Remove\n4.Exit\nChoice : ";
				cin>>choice3;
				
				switch (choice3)
				{
				case 1:
					int g;
					cout<<"Add : ";
					cin>>g;
					b.Add(g);
					cout<<endl;
					break;
				
				case 2:
					b.display();
					cout<<endl;
					break;

				case 3:
					int y;
					cout<<"Remove : ";
					cin>>y;
					b.remove(y);
					cout<<endl;
					break;

				case 4:
					flag3 = 1;
					break;
				
				default:
					cout<<"Please Enter a valid Number"<<endl;
					cout<<endl;
					break;
				}
			}while (flag3 != 1);
			cout<<endl;
			break;

		case 3:
			flag1 = 1;
			break;

		default:
			cout<<"Please Enter a valid Number"<<endl;
			cout<<endl;
			break;
		}
	}while (flag1 != 1);
	
	cout<<"<==========Operations on two Sets==========>\n"<<endl;

	do
	{
		set <int> c;
		int choice3;
		cout<<"1.Intersection\n2.Union\n3.Difference\n4.Subset\n5.Exit\nChoice : ";
		cin>>choice3;

		switch (choice3)
		{
		case 1:
			c.Intersection(a,b);
			cout<<endl;
			break;

		case 2:
			c.Union(a,b);
			cout<<endl;
			break;

		case 3:
			c.Difference(a,b);
			cout<<endl;
			break;

		case 4:
			c.Subset(a,b);
			cout<<endl;
			break;

		case 5:
			flag4 = 1;
			break;
		
		default:
			cout<<"Please enter a Valid Number"<<endl;
			cout<<endl;
			break;
		}
	} while (flag4 != 1);
	return 0;
}
