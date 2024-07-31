class Solution {
public:
    const int MOD = 1e9+7;
    int solve(int daysRem,int absentRem, int lateRem,vector<vector<vector<int>>> &dp){
        if(absentRem < 0) return 0;
        if(lateRem > 2) return 0;
        if(daysRem == 0) return 1;

        if(dp[daysRem][absentRem][lateRem]!=-1){
            return dp[daysRem][absentRem][lateRem];
        }

        //for P
        int count = solve(daysRem - 1,absentRem,0,dp);
        count%=MOD;

        //For A
        count+=solve(daysRem - 1,absentRem - 1,0,dp);
        count%=MOD;

        //For L
        count+=solve(daysRem -1,absentRem, lateRem + 1,dp);
        count%=MOD;

        return dp[daysRem][absentRem][lateRem] = count;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2 + 1, vector<int>(2 + 1, -1)));
        //daysRem, absentremaining, lateRem
        return solve(n,1,0,dp);
    }
};
