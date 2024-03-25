class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //Approach 1
        // unordered_map<int,int> mpp;
        // vector<int> ans;
        // for(int i= 0;i<nums.size();i++)
        // {
        //     mpp[nums[i]]++;
        // }

        // for(auto x : mpp)
        // {
        //     if(x.second > 1)
        //     {
        //         ans.push_back(x.first);
        //     }
        // }


        //Approach 2
        //negate the element at index = nums[i], to mark the visited;
        vector<int> ans;
        for(int i = 0;i<nums.size();i++)
        {
            int index = abs(nums[i]) - 1;

            if(nums[index] < 0)
            {
                ans.push_back(index + 1);
            }
            else{
                nums[index] = -nums[index];
            }
        }

        return ans;
    }
};
