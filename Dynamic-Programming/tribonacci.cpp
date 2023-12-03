class Solution {
public:
    int tribonacci(int n) 
    {
        vector<int>tribonacci={0,1,1};
        if(n<tribonacci.size())
        {
            return tribonacci[n];
        }
        n-=2;
        while(n--)
        {
            int N=tribonacci.size();
            tribonacci.push_back(tribonacci[N-1]+tribonacci[N-2]+tribonacci[N-3]);
        }
        return tribonacci.back();
    }
};
