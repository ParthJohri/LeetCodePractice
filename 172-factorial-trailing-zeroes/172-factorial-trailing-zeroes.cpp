class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        // Formula for trailing zeros = n/5 + n/25 + n/125 + n/625 + .......
        for(int i=5;i<=n;i*=5)
            count = count + n/i;
        return count;
    }
};