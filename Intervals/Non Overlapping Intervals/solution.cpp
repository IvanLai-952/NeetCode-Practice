bool cmp(vector<int>& a, vector<int>& b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        int prev_end=INT_MIN;

        // ordering by end time
        sort(intervals.begin(), intervals.end(), cmp);
        
        for(auto time: intervals){
            // Non-Overlapping
            if(time[0]>=prev_end){
                prev_end=time[1];
            }
            // Overlapping
            else{
                ans++;
            }
        }

        return ans;
    }
};