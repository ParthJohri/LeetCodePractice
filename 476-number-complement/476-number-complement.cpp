class Solution {
public:
    int findComplement(int num) {
        if(num==0)
            return 1;
        int n=log2(num);
        int p=0;
        while(p<=n)
        {
            num^=(1<<p);
            p++;
        }
        return num;
    }
};