class Solution {
public:
    bool isPossible(vector<int> &position,int n,int m,int mid)
    {
        int cnt = 1;
        int iniPos = position[0];

        for(int i = 0;i<n;i++)
        {
            if(position[i] - iniPos < mid)
            {
                continue;
            }
            else{
                cnt++;
                iniPos = position[i];

                if(cnt == m)
                    return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();

        sort(position.begin(),position.end());

        int s = 0;
        int e = position[n-1] - position[0];
        int ans;
        while(s <= e)
        {
            int mid = s + (e-s) / 2;

            if(isPossible(position,n,m,mid))
            {
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }
};

//same as aggressive cows
