class Solution {
public:
    int minSteps(string s, string t) {
        int count[26] = {0};
        int i = 0;

        while(i<s.size())
        {
            count[t[i] - 'a'] ++;
            count[s[i] - 'a'] --;
            i++;
        }
        int ans = 0;
        i = 0;

        while(i<26)
        {
            ans+=max(0,count[i]);
            i++;
        }
        return ans;
    }
};
