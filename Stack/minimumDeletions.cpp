class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        stack<char>st;

        int operations = 0;

        for(int i = n-1;i>=0;i--){
            if(!st.empty() && s[i]=='b' && st.top() == 'a'){
                operations ++;
                st.pop();
            }else{
                st.push(s[i]);
            }
        }

        return operations;
    }
};
