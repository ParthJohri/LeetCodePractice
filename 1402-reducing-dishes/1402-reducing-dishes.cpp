class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int Cumulative_sum=0,ans=0,curr=0;
        for(int i=satisfaction.size()-1;i>=0;i--){
            curr+=Cumulative_sum+satisfaction[i];
            Cumulative_sum+=satisfaction[i];
            ans=max(ans,curr);
        }
        return ans;
    }
};