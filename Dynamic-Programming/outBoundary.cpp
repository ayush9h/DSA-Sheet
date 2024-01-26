class Solution {
public:
    const int MOD = 1000000007;
    int solve(int startRow,int startCol, int m,int n, int maxMove,vector<vector<vector<int>>> &dp)
    {
        //base case
        if(startRow < 0 || startRow >= m || startCol < 0 || startCol >= n)
        {
            return 1;
        }
        if(dp[startRow][startCol][maxMove]!=-1)
            return dp[startRow][startCol][maxMove];

        int up = 0,left = 0,down = 0,right = 0;
        if(maxMove> 0) up = (solve(startRow-1,startCol,m,n,maxMove - 1,dp)) ;
        if(maxMove> 0) down = (solve(startRow + 1,startCol,m,n,maxMove - 1,dp)) ;
        if(maxMove> 0) left = (solve(startRow,startCol-1,m,n,maxMove - 1,dp));
        if(maxMove> 0) right = (solve(startRow,startCol + 1,m,n,maxMove - 1,dp)) ;

        return dp[startRow][startCol][maxMove] = ((up+down) %MOD+ (left+right) % MOD) % MOD;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n,vector<int>(maxMove + 1,-1)));
        return solve(startRow,startColumn,m,n,maxMove,dp);
    }
};
