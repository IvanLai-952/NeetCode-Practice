class Solution {
public:
    int hammingWeight(int n) {
        int nums=0;

        while(n>0){
            if(n%2) nums++;
            n/=2;
        }

        return nums;
    }
};