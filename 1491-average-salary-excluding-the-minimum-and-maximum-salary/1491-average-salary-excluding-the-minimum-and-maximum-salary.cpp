class Solution {
public:
    double average(vector<int>& salary) {
        int sum=0,mn=INT_MAX,mx=INT_MIN;
        for(auto i:salary){
            sum+=i;
            mn=min(mn,i);
            mx=max(mx,i);
        }
        return (double)(sum-(mn+mx))/(salary.size()-2);
    }
};