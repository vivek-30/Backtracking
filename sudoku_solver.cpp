#include<iostream>
#include<math.h>
using namespace std;

// change N form 9 to 4 for a 4*4 board
#define N 9

void print_sudoku_board(int board[][N]){

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<board[i][j]<<" ";

		cout<<endl;
	}
}

bool is_safe_cell(int board[][N],int row,int col,int num){

	if(row<0 || col<0 || row>=N || col>=N)
		return false;

	int n=sqrt(N);

	if(board[row][col])
		return false;

	int starting_row=row-row%n;
	int starting_col=col-col%n;

	//check in a box.	 
	for(int i=starting_row;i<starting_row+n;i++){
		for(int j=starting_col;j<starting_col+n;j++){
			if(board[i][j]==num)
				return false;
		}
	}

	//check in a row.	 
	for(int i=0;i<N;i++){
		if(board[row][i]==num)
			return false;
	}

	//check in a column.
	for(int i=0;i<N;i++){
		if(board[i][col]==num)
			return false;
	}

	return true;
}


bool is_empty_cell(int board[N][N],int& row,int& col){

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(board[i][j]==0){
				row=i;
				col=j;
				return true;
			}
		}
	}

	return false;
}

bool solve_sudoku_board(int (*board)[N]){

	int row=-1,col=-1;

	if(not is_empty_cell(board,row,col)){
		return true;
	}		
			// try all possible number from 1 to N 
			// note-> it should always be from 1 to N and not less than N
			for(int i=1;i<=N;i++){

				if(is_safe_cell(board,row,col,i)){

					board[row][col]=i;

					if(solve_sudoku_board(board))
						return true;

					board[row][col]=0;
				}
			}

	return false;
}

int main(){
	
	int board[N][N]={{3,0,6,5,0,8,4,0,0},
					 {5,2,0,0,0,0,0,0,0},
					 {0,8,7,0,0,0,0,3,1},
					 {0,0,3,0,1,0,0,8,0},
					 {9,0,0,8,6,3,0,0,5},
					 {0,5,0,0,9,0,6,0,0},
					 {1,3,0,0,0,0,2,5,0},
					 {0,0,0,0,0,0,0,7,4},
					 {0,0,5,2,0,6,3,0,0}};

	// another sudoku baord of 4*4 
	// int board[N][N]={{1,3,0,4},
	// 				 {2,0,3,1},
	// 				 {0,1,0,2},
	// 				 {4,0,1,0}};	 

	if(solve_sudoku_board(board))
		print_sudoku_board(board);
	else
		cout<<"no solution exists\n";

	return 0;
}