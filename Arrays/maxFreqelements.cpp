class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(int i = 0 ;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }

        //Find the maximum occurrences
        int maxi = INT_MIN;

        for(auto x : mpp)
        {
            if(x.second > maxi)
            {
                maxi = x.second;
            }
        }

        //check the count of each element = max occurence
        int count = 0;
        for(auto x:mpp)
        {
            if(x.second == maxi)
            {
                count+=x.second;
            }
        }
        return count;

        //space - O(n)
        //time - O(n)
    }
};
