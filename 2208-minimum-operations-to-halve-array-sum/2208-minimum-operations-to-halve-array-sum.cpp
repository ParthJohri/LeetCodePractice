class Solution {
public:
    int halveArray(vector<int>& nums) {
        double ans=0,sum=0,mn;
        priority_queue<double> p;
        for(auto i:nums){
            sum+=i;
            p.push(i);
        }
        mn=sum/2;
        while(sum>mn){
            double v=p.top();
            p.pop();
            sum-=v;
            sum+=v/2;
            p.push(v/2);
            ans++;
        }
        return ans;
    }
};