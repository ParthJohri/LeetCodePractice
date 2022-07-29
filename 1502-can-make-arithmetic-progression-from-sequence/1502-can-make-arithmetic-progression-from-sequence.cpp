class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int d,d1;
        int mn=INT_MAX,mx=INT_MIN,n=arr.size(),mn2=INT_MAX;
        unordered_map<int,int> m;

        double sum=0,sum2=0;
        for(auto i:arr){
            mn=min(mn,i);
            mx=max(mx,i);
            sum+=i;
            m[i]++;
        }
        
        d=(mx-mn)/(n-1);
        sum2=(n*(2*mn+(n-1)*d)/2.0);
        while(--n){
            if(!m.count(mn+d)){
                return false;
            }
            mn=mn+d;
        }
        return sum2==sum;
    }
};