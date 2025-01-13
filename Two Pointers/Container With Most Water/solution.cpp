class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int ans=0;

        while(left<right){
            int tall=min(height[left], height[right]);
            ans=max(ans, tall*(right-left));

            if(height[left]>height[right])
                right--;
            else
                left++;
        }

        return ans;
    }
};