class Solution {
public:
    vector<int> topoSort(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree) {
        queue<int> q;
        vector<int> result;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                result.push_back(i);
                count++;
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    result.push_back(v);
                    count++;
                    q.push(v);
                }
            }
        }

        if (count == n)
            return result; // TopoOrder possible, all courses complete

        return {}; // TopoOrder not possible, cycle detected
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0); // Kahn's algo

        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return topoSort(adj, numCourses, indegree);
    }
};
