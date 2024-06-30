 class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int u)
    {
        if(u == parent[u])
            return u;

        return parent[u] = find(parent[u]);
    }

    void Union(int x,int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return;
        
        if(rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
     }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
            return -1;
        

        parent.resize(n);
        rank.resize(n);

        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
        }

        int components = n;

        for(auto &vec:connections)
        {
            int firstNode = vec[0];
            int secondNode = vec[1];

            if(find(firstNode) != find(secondNode))
            {
                Union(firstNode,secondNode);
                components--;
            }
        }

        return components - 1;
    }
};
