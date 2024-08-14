class Solution {
public:
    int solve(vector<int>&nums, int diff, int n){
        int j = 0;
        int count = 0;
        for(int i = 1;i<n;i++){
            while(nums[i] - nums[j]>diff){
                j++;
            }
            count+=i-j;       
            }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int high = nums[n-1] - nums[0];
        int low = INT_MAX;

        for(int i = 1;i<n;i++){
            if(nums[i] - nums[i-1] < low){
                low = nums[i] - nums[i-1];
            }
        }

        while(low < high){
            int mid = (low + high) / 2;

            int ans = solve(nums,mid,n);

            if(ans<k){
                low=mid + 1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};
