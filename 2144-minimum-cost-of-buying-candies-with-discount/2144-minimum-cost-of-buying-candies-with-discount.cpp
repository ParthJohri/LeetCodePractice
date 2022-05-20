class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans=0,mn=0,i,count=cost.size()/3;
        sort(cost.begin(),cost.end(),greater<int>());
        if(cost.size()==1)
            return cost[0];
        if(cost.size()==2)
            return cost[0]+cost[1];
        for(i=0;i<cost.size()-2;i+=2)
        {
            mn=min(cost[i],cost[i+1]);
            if(cost[i+2]<=mn)
            {
                --count;
                ans+=cost[i]+cost[i+1];
                ++i;
            }
        }
        if(count==0&&i<cost.size())
           {
            while(i<cost.size())
            {
                ans+=cost[i++];
            }
          }
        return ans;
    }
};