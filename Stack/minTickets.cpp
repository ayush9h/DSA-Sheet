class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();

        queue<int> q;

        int ans = 0;

        for(int i = 0 ;i<n;i++)
        {
            q.push(i);
        }

        while(!q.empty())
        {
            int index = q.front();
            q.pop();

            tickets[index]--;
            ans++;

            if(tickets[index] == 0 && index==k)
            {
                return ans;
            }
            if(tickets[index] > 0)
            {
                q.push(index);
            }
        }
        return ans;
    }
};
