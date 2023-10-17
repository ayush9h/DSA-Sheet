#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  stack<char> st;

  for(int i = 0;i<s.size();i++){
    st.push(s[i]);
  }
  string ans = "";
  while(!st.empty()){
    char ch = st.top();
    ans.push_back(ch);
    st.pop();
  }

  cout<<"Reversed String:"<<ans<<endl;
  return 0;
}
