class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<32> b(n);
        if(n<0) return false;
        return (b.count()==1);
    }
};