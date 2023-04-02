class Solution {
public:
    long long digitsum(long long n){
        long long sum=0,temp=n;
        while(n!=0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long mul=1, add=0;
        while(digitsum(n+add)>target){
            mul*=10;
            add=mul-n%mul;
        }
        return add;
    }
};