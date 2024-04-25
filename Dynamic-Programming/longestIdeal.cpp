class Solution {
public:
    //variant of Longest Increasing Subsequence
    int solve(string& s, int k,int ind, int n, vector<vector<int>> &dp, int prevChar)
    {
        if(ind==n) return 0;
        if(dp[ind][prevChar]!=-1) return dp[ind][prevChar];
        if(abs((s[ind]-'a')-(prevChar))<=k || prevChar==26)
        {
            dp[ind][prevChar] = max(1 + solve(s,k,ind+1,n,dp,s[ind]-'a'),solve(s,k,ind + 1,n,dp,prevChar));
        }
        else{
            dp[ind][prevChar] = solve(s,k,ind + 1,n,dp,prevChar);
        }

        return dp[ind][prevChar];
    }
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(127,-1));

        int ans = solve(s,k,0,n,dp,26);
        return ans;
    }
};
