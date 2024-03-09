class Solution {
public:
//Usin HashMaps
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
//Using Two Pointers
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j =0;
        int ans = -1;
        while(i < n && j < m)
        {
            //sorted property to be followed
            if(nums1[i]!=nums2[j] && nums1[i] < nums2[j])
            {
                i++;
            }
            else if(nums1[i]!=nums2[j] && nums1[i] > nums2[j])
            {
                j++;
            }
            else{
                ans = nums1[i];
                break;
            }
        }
        return ans;
    }
};
