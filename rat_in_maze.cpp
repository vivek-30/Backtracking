#include<iostream>
using namespace std;

#define maxsize 10

bool issafe(int maze[][maxsize],int size,int row ,int col,int sol[][maxsize])
{
	if(row<0||col<0||row>=size||col>=size||sol[row][col]==1||maze[row][col]==0)
		return false;
	
	 return true;

}

int flag=0;

void print(int (*sol)[maxsize],int size)
{
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
}

void solvemaze(int maze[][maxsize],int size,int row,int col,int sol[][maxsize])
{
	if(row==size-1&&col==size-1)
	{
		flag=1;
		sol[row][col]=1;
		print(sol,size);
		cout<<"\n\n";
		return;
	}

	if(issafe(maze,size,row,col,sol))
	{
		// place stone to step through it.
		sol[row][col]=1;

		// move up
		solvemaze(maze,size,row-1,col,sol);
		// move down
		solvemaze(maze,size,row+1,col,sol);
		// move left
		solvemaze(maze,size,row,col-1,sol);
		// move right
		solvemaze(maze,size,row,col+1,sol);

		// backtrack and remove previous stone from path.
		sol[row][col]=0;
		return;
	}
		return;
}

int main()
{
	int size;
	cout<<"enter the size of maze\n";
	cin>>size;
	int maze[maxsize][maxsize];

	cout<<"enter maze elements\n";
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			cin>>maze[i][j];

	int solution[maxsize][maxsize];

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			solution[i][j]=0;

	cout<<endl;
	solvemaze(maze,size,0,0,solution);

	if(!flag)
	cout<<"solution to above maze doesnot exists\n";
	
	return 0;
}