class Solution {
public:
    typedef long long ll;
    const long long LARGE_VALUE = 2e9;
    ll solve(vector<vector<int>> &edges, int n, int src, int dest){
        unordered_map<ll, vector<pair<ll,ll>>> adj; // u->{v,w}


        for(vector<int> &edge:edges){
            if(edge[2]!=-1){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
            }
        }


        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

        vector<ll> result(n,INT_MAX);
        vector<bool> visited(n,false);

        result[src] = 0;

        pq.push({0,src});

        while(!pq.empty()){
            ll currDist = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            
            if(visited[node]==true)
                continue;
            
            visited[node] = true;
            for(auto &[neighbor, wt]: adj[node]){
                if(result[neighbor] > currDist + wt){
                    result[neighbor] = currDist + wt;
                    pq.push({result[neighbor], neighbor});
                }
            }
        }

        return result[dest];

    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currShortest = solve(edges, n, source, destination);

        if(currShortest < target){
            return {};
        } // ------ 1

        bool matched = (currShortest == target);

        for(vector<int> &edge:edges){
            if(edge[2]==-1){
                edge[2] = (matched == true) ? LARGE_VALUE : 1;

                if(matched == false){
                    ll newShortest = solve(edges,n,source,destination);

                    if(newShortest <= target){
                        matched = true;
                        edge[2] += (target - newShortest);
                    }
                }
            }
        } // -------3
        if(matched == false){
            return {};
        }

        return edges;
    }
};
