class Solution {
public:
    int reverse(int x) {
        int reverse=0,lastDigit=0,mx=INT_MAX,mn=INT_MIN;
        // INT_MAX  2147483647
        // INT_MIN -2147483648
        while(x!=0)
        {
            lastDigit=x%10;
            if(reverse>mx/10||(reverse==mx&&lastDigit>7))
                return 0;
            if(reverse<mn/10||(reverse==mn&&lastDigit<-8))
                return 0;
            reverse=reverse*10+lastDigit;
            x/=10;
        }
        return reverse;
    }
};