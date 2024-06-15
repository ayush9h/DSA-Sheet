class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int,int>> minCapi;

        for(int i =0;i<n;i++)
        {
            minCapi.push_back({capital[i],profits[i]});
        }

        sort(minCapi.begin(),minCapi.end());

        int i = 0;
        priority_queue<int> pq;
        while(k > 0)
        {
            while(i < n && minCapi[i].first <=w)
            {
                pq.push(minCapi[i].second);
                i++;
            }

            if (pq.empty())
                break;
            
            if(!pq.empty())
            {
                w+=pq.top();
                pq.pop();
            }
            k--;
        }

        return w;
    }
};
