class Solution {
public:
    int solve(int i,int j, int row,int col,vector<vector<int>> &obstacleGrid,vector<vector<int>> &dp)
    {
        //base case
        if(i>=row || j>=col || obstacleGrid[i][j]==1)
            return 0;
        
        if(i==row -1 && j==col - 1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];

        dp[i][j] =  solve(i,j+1,row,col,obstacleGrid,dp) + solve(i+1,j,row,col,obstacleGrid,dp);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int row = obstacleGrid.size();
       int col = obstacleGrid[0].size();
       vector<vector<int>> dp(row, vector<int> (col,-1));
       return solve(0,0,row,col,obstacleGrid,dp); 
    }
};
