class Solution
{
public:
    bool solve(int start, int color[], vector<int> &adj)
    {
        queue<int> q;
        color[start] = 0;
        q.push(start);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (color[it] == -1)
                {
                    color[it] = 1 - color[node];
                    q.push(it);
                }
                else if (color[it] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBarpatite(int V, vector<int> adj)
    {
        int color[V] = {-1};
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (solve(i, color, adj, q) == false)
                    return false;
            }
        }
        return true;
    }
};
