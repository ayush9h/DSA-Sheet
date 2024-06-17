class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int low = 0;
        long long int high = sqrt(c); //no need to run till c

        //edge case
        if(c==1 || c==0)
            return true;
        while(low <= high)
        {
            if(((low * low) + (high * high)) == c)
                return true;
            
            if(((low * low) + (high * high)) > c)
                high--;
            
            else
                low++;
        }
        return false;
    }
};
