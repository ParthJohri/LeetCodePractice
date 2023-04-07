class Solution {
public:
    double pow(double x, int n){
        if(n==0) return 1.00000;
        double val=n%2?x:1;
        val*=pow(x*x,n/2);
        return val;
    }
    double myPow(double x, int n) {
        bool neg=n<0;
        double val=pow(x,n);
        return neg?1/val:val;
    }
};