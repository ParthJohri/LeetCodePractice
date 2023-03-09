class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // 2,3,4,4,9,13;
        int sum=0,ans=0,index=0,mx=INT_MIN;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]!=1){
            ans+=customers[i];
            customers[i]=0;}
        }
        for(int i=0;i<minutes;i++){
            sum+=customers[i];
        }
        mx=max(mx,sum);
        for(int i=minutes;i<customers.size();i++){
            sum+=customers[i]-customers[i-minutes];
            if(grumpy[i]!=1) continue;
            if(mx<sum){
                index=i;
                mx=max(mx,sum);
            }
        }
        ans+=mx;
        return ans;
    }
};