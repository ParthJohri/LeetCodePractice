class Solution {
public:
    long long present(long long mid,vector<int>&v){
        long long k=0;
        if(mid==0) return 0;
        for(auto i:v){
            k+=floor(i/mid);
        }
        return k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=0,mn=1,mx=INT_MIN;
        for(int i=0;i<candies.size();i++){
            sum+=candies[i];
            long long val=candies[i];
            mx=max(mx,val);
        }
        if(sum<k) return 0;
        // mn---mx;
        long long ans=0,mid;
        while(mn<=mx){
            mid=(mn+(mx-mn)/2);
            long long v=present(mid,candies);
            cout<<mid<<" "<<v<<endl;
            if(v>=k){
                ans=mid;
                mn=mid+1;
            }
            else
                mx=mid-1;
        }
        return ans;
    }
};