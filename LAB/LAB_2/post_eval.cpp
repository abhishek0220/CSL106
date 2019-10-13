#include<bits/stdc++.h>
using namespace std;
int check(char c){
	if(c >= '0' && c <= '9')
		return 1;
	return 0;
}
int cal(int b,int a,char c){
	int tem;
	if(c=='-')
		tem=a-b;
	if(c=='+')
		tem=a+b;
	if(c=='*')
		tem=a*b;
	if(c=='/')
		tem=a/b;
	return tem;
}
int post_eval(string s){
	stack<int> st;
	char tem;
	int num,a,b;

	for(int i=0;i<s.length();i++){
		tem=s[i];
		if(check(tem)==1){
			num=tem-'0';
			st.push(num);
		}
		else{
			a=st.top();
			st.pop();
			b=st.top();
			st.pop();
			num=cal(a,b,s[i]);
			st.push(num);
		}
	}
	return st.top();
}
int main(){
	string s="231*+9-";
	int ans=post_eval(s);
	cout<<ans<<endl;
	return 0;
}