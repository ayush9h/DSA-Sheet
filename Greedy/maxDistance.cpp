class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays[0].size();

        int curr_min = arrays[0][0], curr_max = arrays[0][n-1];

        int res = 0;

        for(int i = 1;i<arrays.size();i++){
            int n = arrays[i].size();

            res = max(res, max(arrays[i][n-1] - curr_min,  curr_max - arrays[i][0]));

            curr_max = max(curr_max, arrays[i][n-1]);
            curr_min = min(curr_min, arrays[i][0]);
        }

        return res;
    }
};
