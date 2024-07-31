class Solution {
public:
    int WIDTH;
    int dp[1001][1001];
    int solve(int i, vector<vector<int>>& books, int remW,int height){
        
        if(i >= books.size()){
            return height;
        }

        if(dp[i][remW]!=-1){
            return dp[i][remW];
        }

        int keep = INT_MAX;
        int skip = INT_MAX;

        //keep
        if(books[i][0] <= remW){
            keep = solve(i + 1,books, remW - books[i][0], max(books[i][1],height));
        }

        //skip
        skip = height +  solve(i+1,books,WIDTH - books[i][0], books[i][1]);

        return dp[i][remW] = min(skip,keep);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        WIDTH = shelfWidth;
        int remW = shelfWidth;

        memset(dp,-1,sizeof(dp));
        return solve(0,books,remW,0);
    }
};
