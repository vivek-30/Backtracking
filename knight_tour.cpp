#include<iostream>
using namespace std;

#define N 8

void print(int board[][N]){

cout<<"knight tour is :\n";

for(int i=0;i<N;i++){

for(int j=0;j<N;j++)
cout<<board[i][j]<<" ";

cout<<endl;
}

return;
}

bool is_safe(int board[][N],int row,int col,int move){

if(row<0 or col<0 or row>=N or col>=N or board[row][col])
return false;

if(board[row][col]==move){
	return false;
}

return true;
}

bool knight_tour(int board[][N],int row,int col,int move){

if(move==N*N+1){

board[row][col]=move;
print(board);
board[row][col]=0;
return true;

}

if(is_safe(board,row,col,move)){

		board[row][col]=move;

if(knight_tour(board,row-2,col+1,move+1))
	return true;

if(knight_tour(board,row-1,col+2,move+1))
	return true;

if(knight_tour(board,row+1,col+2,move+1))
	return true;

if(knight_tour(board,row+2,col+1,move+1))
	return true;

if(knight_tour(board,row+2,col-1,move+1))
	return true;

if(knight_tour(board,row+1,col-2,move+1))
	return true;

if(knight_tour(board,row-1,col-2,move+1))
	return true;

if(knight_tour(board,row-2,col-1,move+1))
	return true;

//backtracking
  board[row][col]=0;

 } 

 return false;
}

int main(){

int board[N][N];
for(int i=0;i<N;i++)
for(int j=0;j<N;j++)
board[i][j]=0;

knight_tour(board,0,0,1);

return 0;
}
