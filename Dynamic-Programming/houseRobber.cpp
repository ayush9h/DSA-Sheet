class Solution {
public:
    int rob(vector<int> &nums,int i,vector<int> &dp)
    {
        if(i< 0)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        dp[i] =  max(rob(nums,i-2,dp) + nums[i], rob(nums,i-1,dp));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return rob(nums, nums.size() - 1,dp);
    }
};
