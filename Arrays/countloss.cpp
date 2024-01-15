class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> lmap;
        for(int i = 0;i<matches.size();i++)
        {
            int loss = matches[i][1];
            lmap[loss]++;
        }

        vector<int> zero;
        vector<int> one;
        for(int i = 0;i<matches.size();i++)
        {
            int winner = matches[i][0];
            int loser = matches[i][1];

            if(lmap.find(winner)==lmap.end())
            {
                zero.push_back(winner);
                lmap[winner] = 2;
            }
            if(lmap[loser]==1)
            {
                one.push_back(loser);
            }
        } 
        sort(zero.begin(),zero.end());
        sort(one.begin(),one.end());

        return {zero,one};
    }
};
