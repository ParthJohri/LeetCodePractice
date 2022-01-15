class Solution {
public:
    bool isPowerOfThree(int n) {
        long int temp=1;
        while(temp<n)
            temp+=temp<<1;
        return temp==n;
    }
};