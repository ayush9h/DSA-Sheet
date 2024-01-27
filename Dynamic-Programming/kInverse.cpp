class Solution {
public:
    int MOD = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1,vector<int>(k + 1));

        for(int i =0;i<=n;i++)
        {
            dp[i][0] = 1;
        }

        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=k;j++)
            {
                for(int inv = 0;inv <= min(i-1,j);inv++)
                {
                    dp[i][j] = (dp[i][j] %MOD + dp[i-1][j - inv] %MOD)%MOD;
                }
            }
        }
        return dp[n][k];
    }
};
