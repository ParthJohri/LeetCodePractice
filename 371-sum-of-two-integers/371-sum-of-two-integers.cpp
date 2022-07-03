class Solution {
public:
    int getSum(int a, int b) {
        unsigned int sumxor=0,carry=0;
        // Using unsigned for handling negative overflow like in -1, 1
        do{
            sumxor=a^b;
            carry=a&b;
            carry<<=1;
            a=sumxor;
            b=carry;
        }while(carry!=0);
        return sumxor;
    }
};