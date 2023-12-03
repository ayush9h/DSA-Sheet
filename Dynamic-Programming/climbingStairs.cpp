class Solution {
public:
    int solve(int n,unordered_map<int,int> &mpp)
    {
        if(n == 0 || n==1)
        {
            return 1;
        }

        if(mpp.find(n) == mpp.end())
        {
            mpp[n] = solve(n-1,mpp) + solve(n-2,mpp);
        }
        return mpp[n];
    }
    int climbStairs(int n) {
        unordered_map<int,int>  mpp;
        return solve(n,mpp);
    }
};
