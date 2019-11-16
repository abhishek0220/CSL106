#include<bits/stdc++.h>
using namespace std;

//function to check character scanned
int check(char ch){
	if(ch=='{' || ch=='[' || ch=='(')	//if opening bracket return 1
		return 1;
	if(ch=='}' || ch==']' || ch==')')	//if closing bracket return 2
		return 2;
	return 0;							//else 0
}

//main driver funcction
int main(){
	ifstream fin;
	stack<char> s;
	map<char,char> symbol;	//maping opening bracket to closing bracket
	symbol[']']='[';
	symbol['}']='{';
	symbol[')']='(';
	fin.open("input.txt");	//opening input.txt file
	char ch;
	int con;
	bool allok=true;	//marking file as valid
	//read till end of file
	while(!fin.eof()){
		fin.get(ch);	//taking input character by character
		con=check(ch);	//calling check function
		if(con==0)		//if non bracket then continue
			continue;
		if(con==1)		//if opening bracket then append it to stack
			s.push(ch);
		if(con==2){		//if closing bracket
			if(s.empty() || s.top()!=symbol[ch])	//check whether stack is empty of bracket doesnt match with respective opening bracket
			{
				//then mark valid to invalid and break
				allok=false;		
				break;
			}
			s.pop();	//remove bracket from stack
		}
	}
	fin.close();		//close the file
	if(!s.empty())		//if stack is not empty then also mark it invalid
		allok=false;
	//printing whether file is valid or not
	if(allok)
		cout<<"File OK";
	else
		cout<<"Invalid File";
	return 0;
}