class Solution {
public:
    int sum(int n)
    {
        int s=1,x=2;
        while(x*x<n)
        {
            if(n%x==0)
                {s+=x;
                 s+=n/x;}
            x++;
        }
        return n!=1?s:0;
    }
    bool checkPerfectNumber(int num) {
        cout<<sum(num);
        return num==sum(num);
    }
};