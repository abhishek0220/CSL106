#include<bits/stdc++.h> 
using namespace std; 

int order(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else if(c == '(' || c == ')')
        return 0;
    else
    return -1; 
} 
  
string in_post(string s) 
{ 
    stack<char> st; 
    st.push('N'); 
    int l = s.length(); 
    string post; 
    for(int i = 0; i < l; i++) 
    {  
        if(order(s[i])==-1) 
            post+=s[i]; 
        else if(s[i] == '(') 
        st.push('('); 
        else if(s[i] == ')') 
        { 
            while(st.top() != 'N' && st.top() != '(') 
            { 
                char c = st.top(); 
                st.pop(); 
                post += c; 
            } 
            if(st.top() == '(') 
            { 
                char c = st.top(); 
                st.pop(); 
            } 
        }
        else{ 
            while(st.top() != 'N' && order(s[i]) <= order(st.top())) 
            { 
                char c = st.top(); 
                st.pop(); 
                post += c; 
            } 
            st.push(s[i]); 
        } 
  
    } 
    while(st.top() != 'N') 
    { 
        char c = st.top(); 
        st.pop(); 
        post += c; 
    } 
      
    return post; 
  
}
int main() 
{ 
    string str = "a+b*(c^d-e)"; 
    string ans=in_post(str); 
    cout<<ans<<endl;
    return 0; 
} 