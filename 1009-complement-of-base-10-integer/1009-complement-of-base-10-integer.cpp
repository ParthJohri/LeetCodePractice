class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        int pos=log2(n);
        int p=0;
        while(p<=pos)
        {n=n^(1<<p);
        p++;}
        return n;

    }
};