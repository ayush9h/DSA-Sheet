class Solution {
public:
    bool isOkay(int mid, vector<int> &bloomDay, int m,int k)
    {
        int consecCount = 0;
        int numBouquets = 0;
        for(int i = 0;i<bloomDay.size();i++)
        {
            if(bloomDay[i] <= mid)
            {
                consecCount++;
            }
            else{
                consecCount = 0;
            }
            if(consecCount == k)
            {
                numBouquets++;
                consecCount = 0;
            }
        }

        return (numBouquets >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if((long) m * k > n)
            return -1;

        
        int l = 0;
        int r = *max_element(bloomDay.begin(),bloomDay.end());

        int ans = -1;

        while(l <= r)
        {
            int mid = (l + r) / 2;

            if(isOkay(mid,bloomDay,m,k))
            {
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
