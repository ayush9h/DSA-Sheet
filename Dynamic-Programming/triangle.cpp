class Solution {
public:
    int solve(vector<vector<int>> &triangle,int i,int j,int n,vector<vector<int>> &dp)
    {
        if(i == n-1) return triangle[i][j];

        if(dp[i][j]!=-1)
            return dp[i][j];

        int down = triangle[i][j] + solve(triangle,i+1,j,n,dp);
        int diag = triangle[i][j] + solve(triangle,i+1,j+1,n,dp);

        dp[i][j] =  min(down,diag);
        return dp[i][j];

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(triangle,0,0,n,dp);
    }
};
