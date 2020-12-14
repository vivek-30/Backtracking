#include<iostream>
using namespace std;

void print(int** board,int N){

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			if(board[i][j])
			cout<<"Q ";
		else
			cout<<"_ ";

		cout<<endl;
	}
}

bool is_safe(int **board,int N,int row,int col){

	if(row<0 or col<0 or col>=N or row>=N)
		return false;

	// check in upper column
	for(int i=row;i>=0;i--){
		if(board[i][col])
			return false;
	}

	int j=col;
	// check in upper left diagonal
	for(int i=row;i>=0 and j>=0;i--){
		if(board[i][j])
			return false;
		j--;
	}

	j=col;
	// check in upper right diagonal
	for(int i=row;i>=0 and j<N;i--){
		if(board[i][j])
			return false;
		j++;
	}

	return true;
}

void place_n_queen(int **board,int N,int row){

	if(row==N){
		print(board,N);
		cout<<endl<<endl;
		return;
	}

	for(int col=0;col<N;col++){

		if(is_safe(board,N,row,col)){
			board[row][col]=1;

			place_n_queen(board,N,row+1);

			board[row][col]=0;
		}
	}

	return;
}

void N_queen_util(int N){

	if(N<=0)
		return;

	int **board=new int*[N];
	for(int i=0;i<N;i++){
		board[i]=new int[N];
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			board[i][j]=0;
		}
	}

	place_n_queen(board,N,0);

	for(int i=0;i<N;i++){
		delete[] board[i];
	}

	delete[] board;
	return;

}

int main(){
	int N;
	cout<<"enter total number of queen\n";
	cin>>N;

	N_queen_util(N);
	return 0;
}