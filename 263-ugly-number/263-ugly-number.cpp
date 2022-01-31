class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)
            return false;
        if(n==1)
            return true;
        int x=2;
        while(x<n)
        {
            if(n%x==0)
            {n/=x;}
            else
            {
                x++;
            }
            if(x>5)
                return false;
        }
        return true;
    }
};