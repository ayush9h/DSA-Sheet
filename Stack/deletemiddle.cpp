#include<bits/stdc++.h>
using namespace std;
void deleteMiddle(stack<int> s,int count)
{
    int size = s.size();
    
    //base case
    if(count == n / 2)
    {
        stack.pop();
        return;
    }
    
    int num = st.top();
    st.pop();
    
    deleteMiddle(s,count + 1);
    
    s.push(num);
}
