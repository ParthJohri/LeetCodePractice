class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1)
            return false;
        int s=0xaaaaaaaa;
            if ((n&(n-1))==0 && (n&s)==0)
        return true;

        else
            return false;
    }
};