#define ll long long
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ll n = nums.size();
        sort(nums.begin(),nums.end());
        ll prefSum = nums[0] + nums[1];
        ll ans = -1;
        for(int i = 2;i<n;i++)
        {
            if(prefSum > nums[i])
            {
                ans = max(ans,prefSum + nums[i]);
            }
            prefSum+=nums[i];
        }
        return ans;
    }
};
