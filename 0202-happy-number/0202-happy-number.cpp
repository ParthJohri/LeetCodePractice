class Solution {
public:
    map<int,int> m;
    bool isHappy(int n) {
        if(n==1) return true;
        if(m[n]!=0) return false;
        int sum=0;
        m[n]++;
        while(n!=0){
            int d=n%10;
            sum+=d*d;
            n/=10;
        }
        return isHappy(sum);
    }
};