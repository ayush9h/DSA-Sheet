class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int minDiff = INT_MAX;
        //base
        if(n<=3)
            return 0;
        
        sort(nums.begin(),nums.end());
        
        minDiff = min(minDiff, nums[n-4] - nums[0]);
        minDiff = min(minDiff, nums[n-1] - nums[3]);
        minDiff = min(minDiff, nums[n-2] - nums[2]);
        minDiff = min(minDiff, nums[n-3] - nums[1]);

        return minDiff;
    }
};
