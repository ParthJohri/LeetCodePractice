class Solution {
public:
    int sum(int n)
    {
        int s=0,x=1;
        while(x<=n/2)
        {
            if(n%x==0)
                s+=x;
            x++;
        }
        return s;
    }
    bool checkPerfectNumber(int num) {
        return num==sum(num);
    }
};