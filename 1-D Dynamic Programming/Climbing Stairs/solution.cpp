class Solution {
public:
    int climbStairs(int n) {
        vector<int> step(n);
        step[0]=1;
        if(n==1)
            return step[0];

        step[1]=2;

        // k step can be reached from (k-1) step and (k-2) step 
        for(int i=2; i<n; i++){
            step[i]=step[i-1]+step[i-2];
        }

        return step[n-1];
    }
};