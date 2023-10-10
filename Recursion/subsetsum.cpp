void solve(int ind, vector<int>&arr,vector<int> &ans, int sum,int n)
    {
        if(ind == n)
        {
            ans.push_back(sum);
            return;
        }
        
        solve(ind + 1,arr,ans,sum + arr[ind] ,n);
        solve(ind + 1,arr,ans,sum,n);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(0,arr,ans,0,N);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
