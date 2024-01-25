class Solution {
public:
    int solve(int ind1,int ind2,string &text1,string &text2,vector<vector<int>> &dp)
    {
        if(ind1==text1.size() || ind2==text2.size())
        {
            return 0;
        }

        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        int lenCount = 0;

        if(text1[ind1] == text2[ind2])
        {
            lenCount = 1 + solve(ind1 + 1,ind2 + 1,text1,text2,dp);
        }
        else{
            lenCount = max(solve(ind1 + 1,ind2,text1,text2,dp),solve(ind1,ind2 + 1,text1,text2,dp));
        }

        return dp[ind1][ind2] = lenCount;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(0,0,text1,text2,dp);
    }
};
