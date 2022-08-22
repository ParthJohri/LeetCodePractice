class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        if(n==1) return true;
        while(n>9){
            if(n%4!=0) return false;
            n/=4;
        }
        return n==4;
    }
};