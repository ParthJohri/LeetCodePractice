class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int k=31,p=0;
        long long int sum=0;
        while(k>=0)
        {
            int c=(n&(1<<p));
            if(c>0)
                sum+=1*pow(2,k);
            k--;
            p++;
        }
        if(((n>>31)&1)>0)
            sum+=1;
        return sum;
    }
};