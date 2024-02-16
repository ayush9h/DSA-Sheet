class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;

        int n = arr.size();

        for(int i = 0;i<n;i++)
        {
            mpp[arr[i]]++;
        }

        vector<int> freqVector;
        for(auto it: mpp)

        {
            freqVector.push_back(it.second);
        }

        sort(freqVector.begin(),freqVector.end());

        int totalRemoved = 0;
        for(int i = 0;i<freqVector.size();i++)
        {
            totalRemoved+=freqVector[i];

            if(totalRemoved > k) return freqVector.size() - i;
        }

        return 0;
    }
};
