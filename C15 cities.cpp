#include <iostream>
#define infi 100
using namespace std;


class Graph
{
	private:
		int **G;
		int V;
		
	public:
		Graph()
		{
			cout<<"Enter the number of Vertices : ";
			cin>>V;
			
			G = new int* [V];
			for(int i =0; i<V; i++)
			{
				G[i] = new int[V];
				for(int j=0; j<V; j++)
				{
					G[i][j] = 0;
				}
			}
		}
		
		void add_Edges()
		{
			for(int i =0; i<V;i++)
			{
				for(int j =0; j<V;j++)
				{
					char C;
					cout<<"Is there an edge in between "<<i<<" and "<<j<<" y/n : ";
					cin>>C;
					switch(C)
					{
						case 'y' :
							if(G[i][j] == 0)
							{
								int q;
								cout<<"Value : ";
								cin>>q;
								
								G[i][j] = q;
								G[j][i] = q;
							}
							else
							{
								continue;
							}
							break;
							
						case 'n':
							G[i][i] = infi;
							break;
					}
				}
			}
		}
		
		void display()
		{
			cout<<"Adjancy matrix : "<<"\n\n";
			cout<<"\t   ";
			for(int i =0; i<V; i++)
			{
				cout<<i<<" ";
			}
			cout<<"\n";
			for(int i =0; i<V; i++)
			{
				cout<<"\t";
				cout<<i<<" ";
				for(int j =0; j<V; j++)
				{
					cout<<" "<<G[i][j];
				}
				cout<<endl;
			}
		}
		
		void prims_algo()
		{
			int parent[V];
			int key[V];
			bool visited[V];
			
			for(int i = 0; i<V; i++)
			{
				key[i] = infi;
				visited[i] = false;
			}
			
			key[0] = 0;
			parent[0] = -1;
			
			//main code for MST
			for(int count = 0; count<V-1; count ++)
			{
				int u, min_value = infi;
				for(int v = 0; v<V; v++)
				{
					if(visited[v] == false && key[v] < min_value)
					{
						min_value = key[v];
						u = v;
					}
				}
				
				visited[u] = true;
				
				for(int v =0; v<V ; v++)
				{
					if(G[u][v] && visited[v] == false && G[u][v]<key[v])
					{
						parent[v] = u;
						key[v] = G[u][v];
					}
				}
			}
			
			cout<<"Minimum Spanning tree : "<<"\n";
			for (int i = 1; i < V; i++)
	        {
	            cout << "Edge: " << parent[i] << " - " << i << "   Weight: " << G[i][parent[i]] << endl;
	        }

		}
};


int main()
{
	Graph g;
	g.add_Edges();
	g.display();
	g.prims_algo();
	return 0;
}



