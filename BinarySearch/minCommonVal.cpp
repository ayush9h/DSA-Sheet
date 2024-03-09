class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mpp1;
        for(int i = 0;i<nums1.size();i++)
        {
            mpp1[nums1[i]]++;
        }

        int ans = -1;
        for(int i = 0; i<nums2.size();i++)
        {
            if(mpp1[nums2[i]] >= 1)
            {
                ans = nums2[i];
                break;
            }
        }

        return ans;

        //time - O(N)
        //space - O(N)
    }
};
