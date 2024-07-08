class Solution {
public:
    int RR(int n, int k){
        if(n==1) return 0;

        return (RR(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {

        int ans = RR(n,k) + 1;

        return ans;
        
    }
};
