class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> pr(n,0),su(n,0);
        pr[0]=height[0];
        su[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            pr[i]=max(pr[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            su[i]=max(su[i+1],height[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=abs(height[i]-min(pr[i],su[i]));
        }
        return sum;
    }
};