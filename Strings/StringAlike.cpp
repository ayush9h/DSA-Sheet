class Solution {
public:
    bool halvesAreAlike(string s) {
        int leftHalve = 0;
        int rightHalve = 0;

        int n = s.size();

        for(int i = 0;i < n/2;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                leftHalve++;
            }
        }

        for(int i = n/2;i < n;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                rightHalve++;
            }
        }
        
        if(leftHalve == rightHalve)
            return true;
        
        return false;
    }
};
