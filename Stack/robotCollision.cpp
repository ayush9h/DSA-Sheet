class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        stack<int>st;
        vector<int> ans;
        vector<pair<int,int>> vec; //position paired with index

        for(int i = 0; i < n ; i++){
            vec.push_back({positions[i], i});
        }

        sort(vec.begin(),vec.end()); //sort according to positon

        for(int i = 0; i< n;i++)
        {
            int ind = vec[i].second;
            if(directions[ind] == 'L')
            {
                if(st.empty())
                {
                    ans.push_back(ind);
                    continue;
                }

                while(!st.empty() && healths[st.top()] < healths[ind])
                {
                    healths[ind]--;
                    st.pop();
                }

                if(st.empty()) ans.push_back(ind);
                else{
                    if(healths[st.top()] == healths[ind]) st.pop();
                    else{
                        healths[st.top()]--;
                        if(healths[st.top()]==0) st.pop(); 
                    }
                }
            }
            else{
                st.push(ind); //FOR RIGHT DIRECTION
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        sort(ans.begin(),ans.end());

        for(int i=0;i<ans.size();i++) ans[i] = healths[ans[i]];

        return ans;
    }
};
