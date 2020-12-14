#include<iostream>
using namespace std;

void swap(char* a,char* b) { 
	char temp; 
	temp=*a; 
	*a=*b; 
	*b=temp; 
} 

 // count total permutations
 int count=1;
 
void print_permutation(char *str,int len,int fix) { 
	if(len<=0) 
	return; 
 
	if(fix==len+1) { 
	cout<<::count<<". "<<str<<endl; 
	::count++;
	return; 
	 } 
 
	for(int i=fix;i<=len;i++) { 
	swap(str[i],str[fix]); 
	print_permutation(str,len,fix+1); 

	// backtracking swapping back character in the string
	swap(str[i],str[fix]); 
	 } 
 
 return; 
 }
 
int main() { 
int len; 
cout<<"enter string lenght\n";
cin>>len; 
 
char str[len+1]; 
cout<<"enter the string\n"; 
cin>>str; 

cout<<"required permutations of string "<<str<<" are :\n";
print_permutation(str,len-1,0);
 
return 0; 
 }
