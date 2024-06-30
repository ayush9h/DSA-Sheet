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

        if(x_parent == y_parent)
            return;

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
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
             rank.resize(26);

             for(int i = 0;i<26;i++)
             {
                parent[i] = i;
             }     

             for(string&s:equations)
             {
                if(s[1]=='=')
                {
                    Union(s[0]-'a',s[3]-'a');
                }
             }

            for(string &s:equations)
            {
                if(s[1]=='!')
                {
                    char first = s[0];
                    char second = s[3];

                    int firstParent = find(first-'a');
                    int secondParent = find(second - 'a');

                    if(firstParent == secondParent)
                        return false;
                }
            }

            return true;
    }
};
