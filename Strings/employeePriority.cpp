class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        int n = access_times.size();
        vector<string>ans;
        // creating a unordered map
        unordered_map<string, vector<int>> mp;
        for(auto it:access_times)
        {
            string a = it[0];
            int t = stoi(it[1]);

            mp[a].push_back(t);
        }

        for(auto &[key,val] : mp)
        {
            sort(val.begin(),val.end());

            int sz = val.size();
            bool flag = false;

            for(int i = 0;i + 3<=sz;i++)
            {
                if(val[i+2] - val[i] < 100)
                    flag = true;
            }
            if(flag) ans.push_back(key);
        }
        return ans;
    }
};
