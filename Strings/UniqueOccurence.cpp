class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp;
        int n = arr.size();

        for(int i = 0;i<n;i++)
        {
            mpp[arr[i]]++;
        }
        set<int>s;

        for (auto [n,f]:mpp) s.insert(f);
        return mpp.size()==s.size();
    }
};
