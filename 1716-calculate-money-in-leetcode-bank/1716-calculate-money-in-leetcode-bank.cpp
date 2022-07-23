class Solution {
public:
    int totalMoney(int n) {
        int sum=0,mon=1,x=1;
        for(int i=1;i<=n;i++){
            sum+=x;
            if(i%7==0)
                x=mon++;
            x++;
        }
        return sum;
    }
};