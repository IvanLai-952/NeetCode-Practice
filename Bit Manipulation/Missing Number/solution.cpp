class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        // Keep all XOR result
        for(int i=0; i<=n; i++){
            ans=ans^i;
        }

        // k^k=0
        for(int i=0; i<n; i++){
            ans=ans^nums[i];
        }

        return ans;
    }
};