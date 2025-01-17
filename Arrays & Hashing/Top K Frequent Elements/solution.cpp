bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first>b.first;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> CountNum;
        vector<int> result;
        int start=0;

        sort(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=nums[i-1]){
                CountNum.push_back({i-start, nums[start]});
                start=i;
            }
        }
        CountNum.push_back({nums.size()-start, nums[start]});

        sort(CountNum.begin(), CountNum.end(), cmp);

        for(int i=0; i<k; i++){
            result.push_back(CountNum[i].second);
        }

        return result;
    }
};