class Solution {
public:
    int reverse(int num)
    {
        int res=0;
        while(num)
        {
            res=res*10+num%10;
            num=num/10;
        }
        return res;
    }
    bool isSameAfterReversals(int num) {
       int res1=reverse(num),res2=reverse(res1);
       return num==res2;
    }
};