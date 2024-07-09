class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        double totalWaiting = 0;
        int currTime = 0;

        for(int i = 0;i<n;i++)
        {
            if(customers[i][0] >= currTime)
            {
                totalWaiting += (customers[i][1]);

                currTime = customers[i][0] +  customers[i][1];
            }
            else{
                totalWaiting += (currTime - customers[i][0]) + customers[i][1];
                currTime += customers[i][1];
            }
        }


        return totalWaiting / n;
    }
};
