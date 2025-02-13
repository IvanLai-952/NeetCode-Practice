class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> myset;

        for(auto val: nums){
            if(myset.find(val)!=myset.end())
                return true;

            myset.insert(val);
        }
        return false;
    }
};