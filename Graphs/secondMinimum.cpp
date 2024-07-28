class Solution {
public:
    #define P pair<int,int>
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<int>> adj;

        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> d1(n + 1,INT_MAX);
        vector<int> d2(n+1,INT_MAX);

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,1});
        d1[1] = 0;

        while(!pq.empty()){
            auto [timePass,node] = pq.top();
            pq.pop();

            //Final Answer
            if(node==n && d2[n]!=INT_MAX){
                return d2[n];
            }

            int div = timePass / change;
            if(div % 2 == 1){
                timePass = change *(div + 1);
            }

            for(auto &neigh: adj[node]){
                if(d1[neigh] > timePass + time){
                    d2[neigh]= d1[neigh];
                    d1[neigh] = timePass + time;
                    pq.push({timePass+time, neigh});
                }
                else if(d2[neigh] > timePass + time && d1[neigh]!= timePass + time){
                    d2[neigh] = timePass + time;
                    pq.push({timePass + time,neigh});
                }
            }

        }
        return -1;
    }
};
