class Solution {
public:
    vector<int> grayCode(int n) {
        int pn=(int)pow(2,n);
        vector<int> v(pn,0);
        for(int i=0;i<pn;i++){
            v[i]=i^(i>>1);
        }
        return v;
            /*
    typedef unsigned int uint;

// This function converts an unsigned binary number to reflected binary Gray code.
uint BinaryToGray(uint num)
{
    return num ^ (num >> 1); // The operator >> is shift right. The operator ^ is exclusive or.
}

// This function converts a reflected binary Gray code number to a binary number.
uint GrayToBinary(uint num)
{
    uint mask = num;
    while (mask) {           // Each Gray code bit is exclusive-ored with all more significant bits.
        mask >>= 1;
        num   ^= mask;
    }
    return num;
}

// A more efficient version for Gray codes 32 bits or fewer through the use of SWAR (SIMD within a register) techniques. 
// It implements a parallel prefix XOR function. The assignment statements can be in any order.
// 
// This function can be adapted for longer Gray codes by adding steps.

uint GrayToBinary32(uint num)
{
    num ^= num >> 16;
    num ^= num >>  8;
    num ^= num >>  4;
    num ^= num >>  2;
    num ^= num >>  1;
    return num;
}
// A Four-bit-at-once variant changes a binary number (abcd)2 to (abcd)2 ^ (00ab)2, then to (abcd)2 ^ (00ab)2 ^ (0abc)2 ^ (000a)2.
    */
    }
};