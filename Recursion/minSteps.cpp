class Solution {
public:
    int solve(int lastCopiedLength, int currLength ,int n){
        if(currLength == n){
            return 1;
        }

        //invalid operation
        if(currLength > n){
            return 2001;
        }

        int copyPaste = 2 + solve(currLength, currLength + currLength,n);
        int paste = 1 + solve(lastCopiedLength, currLength + lastCopiedLength,n);

        return min(copyPaste,paste);
    }
    int minSteps(int n) {
        //base case

        if(n==1){
            return 0;
        }

        return solve(1,1,n);
    }
};
