class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        int ans=0;

        for(auto val: nums){
            numSet.insert(val);
        }

        for(auto num: numSet){
            int currval=num;
            int length=1;

            // find min num in sub consecutive sequence
            if(numSet.find(currval-1)==numSet.end()){
                // find next num
                while(numSet.find(currval+1)!=numSet.end()){
                    currval++;
                    length++;
                }
                ans=max(ans, length);
            }
        }

        return ans;
    }
};