class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &meeting:meetings)
        {
            adj[meeting[0]].push_back({meeting[1],meeting[2]});
            adj[meeting[1]].push_back({meeting[0],meeting[2]});
        }

        //sort on the basis of time
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        //{time, person}
        pq.push({0,firstPerson});
        pq.push({0,0});

        vector<int> ans;
        vector<int> vis(n,false);

        while(!pq.empty())
        {
            int time = pq.top().first;
            int person = pq.top().second;

            pq.pop();

            if(vis[person])
                continue;
            
            vis[person] = true;

            for(auto neigh:adj[person])
            {
                if(!vis[neigh.first] && time <=neigh.second)
                {
                    pq.push({neigh.second, neigh.first});
                }
            }
        }

        //all visited knows the secret
        for(int i = 0;i<n;i++)
        {
            if(vis[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
