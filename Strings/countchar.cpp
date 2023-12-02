class Solution {
public:
    bool canform(string &word,vector<int> counts)
    {
        vector<int> c(26,0);
        for(char ch:word)
        {
            int x = ch - 'a';
            c[x]++;

            if(c[x] > counts[x])
            {
                return false;
            }
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        vector<int> counts(26,0);
        for(char ch: chars)
        {
            counts[ch - 'a']++;
        }

        int result = 0;

        for(string &word:words)
        {
            if(canform(word,counts))
            {
                result+=word.length();
            }
        }
        return result;
    }
};
