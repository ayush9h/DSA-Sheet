class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;

        int n = s.size();

        for(int i = 0;i<n;i++)
        {
            if(s[i]=='(') st.push(i);
            else if(s[i]==')')
            {
                reverse(s.begin() + st.top(),s.begin() + i);
                st.pop();
            }
        }

        string ans = "";
        for(auto&c:s)
        {
            if(c!=')' && c!='(')
            {
                ans+=c;
            }
        }

        return ans;
    }
};
