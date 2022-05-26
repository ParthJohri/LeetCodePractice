class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool b=(n&1)!=0;
        n=n>>1;
        while(n!=0)
        {
            if(b)
            {
                if((n&1)!=0)
                    return false;
            }
            else
            {
                if((n&1)==0)
                    return false;
            }
            n=n>>1;
            b=!b;
        }
        return true;
    }
};