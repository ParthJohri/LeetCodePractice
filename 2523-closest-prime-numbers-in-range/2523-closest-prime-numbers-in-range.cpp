class Solution {
public:
    vector<bool> sieve(long long n){
        vector<bool> prime(n+1,true);
        prime[0]=prime[1]=false;
        // 2 is the smallest prime number
        for(long long i=2;i<=n;i++){
            if(prime[i]){
                for(long long j=i*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }
        return prime;
    }
    vector<int> closestPrimes(int left, int right) {
        int mn=INT_MAX;
        int temp1=-1,temp2=-1,tmp1=-1,tmp2=-1;
        vector<bool> prime=sieve(right+1);
        for(int i=left;i<=right;i++){
            if(prime[i]==true){
                if(tmp1==-1) {tmp1=i; continue;}
                if(tmp2==-1) {tmp2=i;
                           mn=abs(tmp2-tmp1);
                            temp1=tmp1;
                            temp2=tmp2; 
                            continue;
                }
                tmp1=tmp2;
                tmp2=i;
                if(abs(tmp2-tmp1)<mn){
                mn=abs(tmp2-tmp1);
                temp1=tmp1;
                temp2=tmp2;
                }
            }
        }
        if(temp1==-1 or temp2==-1) return {-1,-1};
        return {temp1,temp2};
    }
};