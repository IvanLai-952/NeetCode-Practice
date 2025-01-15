class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);

        for(int i=1; i<=n; i++){
            int HighBit=log2(i);
            int ref=pow(2,HighBit);
            ans[i]=ans[i%ref]+1;
        }

        return ans;
    }
};