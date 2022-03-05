class Solution {
public:
    int sod(int n)
    {
        int sum=0;
        while(n!=0)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int countBalls(int lowLimit, int highLimit) {
        vector<int>s(46,0);
        int lar=INT_MIN;
        for(int i=lowLimit;i<=highLimit;i++)
        {
            s[sod(i)]++;
            if(s[sod(i)]>lar)
                lar=s[sod(i)];
        }
        return lar;
    }
};