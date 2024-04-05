class Solution {
public:
    string makeGood(string s) {
        stack<int> st;

        int n = s.size();

        for(int i = 0; i<n;i++)
        {
            if(!st.empty() && abs(st.top() - s[i]) == 32)
            {
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        string ans = "";

        while(!st.empty())
        {
            char c = st.top();
            st.pop();
            ans += c;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
