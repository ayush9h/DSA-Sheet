#include<bits/stdc++.h>
using namespace std;
bool validParanthesis(string s)
{
    stack<char> st;
    for(int i = 0; i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            st.push(s[i]);            
        }
        else{
            if(!st.empty())
            {
                char top = st.top();
                if(top==')'&& s[i]=='(' || top=='}' && s[i]=="{" || top ==']' && s[i]=='[')
                {
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    
    if(s.empty())
    {
        return true;
    }
    else{
        return false;
    }
}
