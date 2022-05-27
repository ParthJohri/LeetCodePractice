class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        // Note: The popcount function is a C++ 20 standard builtin function that counts set bits. LeetCode uses g++ compiler with the C++17 standard so we can use __builtin_popcount instead. For other compilers please use bitset<32>().count().
        while(c!=0 || a!=0 || b!=0)
        {
            if( (a&1)!=0 && (b&1)!=0 && (c&1)==0)
                count+=2;
            else if( ((a&1)|(b&1))!=(c&1))
                count++;
            c=c>>1;
            a=a>>1;
            b=b>>1;
        }
        return count;
    }
};