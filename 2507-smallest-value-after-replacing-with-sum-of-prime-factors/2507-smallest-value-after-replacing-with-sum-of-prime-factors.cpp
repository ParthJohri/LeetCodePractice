class Solution {
public:
    int primeFactor(int n){
        long long sum=0;
        for(int i=2;i*i<=n;i++){
            while(n%i==0){
                sum+=i;
                n/=i;
            }
        }
        if(n>1) sum+=n;
        return sum;
    }
    bool prime(int n){
        if(n==2 or n==3 or n==5 or n==7) return true;
        else if(n%2==0 or n%3==0 or n%5==0 or n%7==0) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int smallestValue(int n) {
        map<int,int> m;
        while(!prime(n)) {
            n=primeFactor(n);
            m[n]++;
            if(m[n]==2) break;
        }
        return n;
    }
};