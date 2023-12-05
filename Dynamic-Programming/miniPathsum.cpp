class Solution {
public:
    int solve(int i,int j, int row,int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        //base case
        //to avoid considering the path.......
        if(i >= row || j >= col)
            return INT_MAX;
        
        if(i==row - 1 && j==col - 1)
            return grid[i][j];

        if(dp[i][j]!=-1)
            return dp[i][j];

        dp[i][j] = min(solve(i+1,j,row,col,grid,dp),solve(i,j+1,row,col,grid,dp)) + grid[i][j];
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int> (col,-1));
        return solve(0,0,row,col,grid,dp);
    }
};
