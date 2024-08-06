class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26,0);
        int ans = 0;

        for(char &ch:word){
            mp[ch-'a']++;
        }

        sort(mp.begin(),mp.end(),greater<int>());

        for(int i = 0;i<26;i++){
            int freq = mp[i];

            int presses = (i / 8) + 1;

            ans += presses*freq;
        }

        return ans;
    }
};
