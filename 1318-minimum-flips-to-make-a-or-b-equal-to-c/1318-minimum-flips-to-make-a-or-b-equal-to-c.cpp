class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
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