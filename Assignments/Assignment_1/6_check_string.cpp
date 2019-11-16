#include<bits/stdc++.h>
using namespace std;

//string comparison function
bool compare(string a,string b){
	int i=0;
	bool check;
	string tem,tem2,text;
	//itirating each character of text2
	for(int i=0;i<b.length();i++)
		if(b[i]==a[0]){	//if first char of text1 matches with i`th characcter of text 2
			tem=b.substr(i+1);
			tem2=b.substr(0,b.length()-tem.length()-1);
			text=tem+tem2;	//created tem text of b in clockwise such than i+1`th positon be at 0
			check=text.compare(a.substr(1));	//comparing with a
			if(check==0)
				return true;
			tem=b.substr(i+1);
			tem2=b.substr(0,b.length()-tem.length()-1);
			reverse(tem.begin(), tem.end());
			reverse(tem2.begin(), tem2.end());
			text=tem2+tem;	//created tem text of b in anti-clockwise such than i-1`th positon be at 0
			check=text.compare(a.substr(1));	//comparing with a
			if(check==0)
				return true;
			
		}
	return false;
}

//main driver funtion
int main(){
	string text1,text2;
	cout<<"Enter text 1 : ";
	cin>>text1;
	cout<<"Enter text 2 : ";
	cin>>text2;
	bool ch=0;
	//if lenght of both text equal
	if(text1.length()==text2.length())
		ch=compare(text1,text2);	//calling compare function
	if(ch)	//if compare returns non zero
		cout<<"Can be derived";
	else	//if compare returns zero
		cout<<"Cannot be derived";
	return 0;
}