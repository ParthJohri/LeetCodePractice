class Solution {
public:
    bool isThree(int n) {
        int c=0;
        for(int i=1;i*i<=n;i++)
        {
            if(i*i==n)
                c++;
            else if(n%i==0)
            c+=2;
        }
        return c==3;
    }
};