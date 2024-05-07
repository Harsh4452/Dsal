
#include<iostream>
using namespace std;
class graph{
	int a[20][20];
	int vis[20];
	int n;
	public:
		graph(){
			cout<<"enter the number of vertices "<<endl;
			cin>>n;
			for(int i=0;i<n;i++){
				vis[i]=0;	
			}
		}
		void readgraph(){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cin>>a[i][j];
				}
				cout<<endl;
			}
		}
		void printgraph(){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout<<a[i][j];
				}
				cout<<endl;
			}
		}
		void prims()
		{
			int b[10][10];
			int cost[10][10];
			int disp[10];
			int from[10];
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					b[i][j]=0;
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(a[i][j]==0)
					{
						cost[i][j]=100;
					}
					else
					{
						cost[i][j]=a[i][j];
					}
					
				}
			}
			for(int i=0;i<n;i++)
			{
				disp[i]=cost[0][i];
				from[i]=0;
			}
			int edges=n-1;
			int i=0;
			int u;
			int v;
			int total=0;
			while(i<edges)
			{
				i++;
				int min=100;
				for(int i=1;i<n;i++)
				{
					if(disp[i]<min && vis[i]==0)
					{
						min=disp[i];
						v=i;
						
					}
					
				}
				u=from[v];
				b[v][u]=cost[u][v];
				b[u][v]=cost[u][v];
				total=total+cost[u][v];
			
			
			vis[v]=1;
			for(int i=1;i<n;i++)
			{
				if(disp[i]>cost[v][i] && vis[i]==0)
				{
					disp[i]=cost[v][i];
					from[i]=v;
					
				}
			}
			
			
			}	
			
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					cout<<"\t"<<b[i][j];
				}
				cout<<endl;
			}
			
			cout<<"\nTotal Cost of MSt is"<<total;			
		}
	
			
		
};
int main(){
	graph g;
	int choose;
	int a;
	int flag = 0;
	do{
		
		cout<<"1.readgraph \n2.printgraph \n3.prims\n4.End\nChoose : "<<endl;
		cin>>choose;
		if(choose==1){
			g.readgraph();
		}
		if(choose==2){
			g.printgraph();
		}
		if(choose==3){
			g.prims();
		}
		if(choose==4){
			flag = 1;
		}
		else{
			cout<<"Please Choose Given Values";
		}
	}while(flag != 1);
	
}

