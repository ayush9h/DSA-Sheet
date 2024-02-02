class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;
        for(int i = 1; i<=8;i++)
        {
            q.push(i);
        }

        vector<int> res;

        while(!q.empty())
        {
            int temp = q.front();
            q.pop();

            if(temp >=low && temp <= high)
            {
                res.push_back(temp);
            }

            int last = temp%10;
            if(last+1 <=9)
            {
                q.push(temp * 10 + (last + 1));
            }
        }
        return res;
    }
};
