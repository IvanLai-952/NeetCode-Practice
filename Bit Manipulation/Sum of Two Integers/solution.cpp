class Solution {
public:
    int getSum(int a, int b) {

        while(b){
            int sum=a^b;  //sum without carry
            int carry=(a&b)<<1;  //carry shift left
            a=sum;
            b=carry;
        }

        return a;
    }
};