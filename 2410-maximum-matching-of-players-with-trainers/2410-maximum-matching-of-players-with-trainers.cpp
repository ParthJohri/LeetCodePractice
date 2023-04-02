class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int ans=0,j=0,n=trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        for(auto i:players){
            // auto index=lower_bound(trainers.begin(),trainers.end(),i);
            // if(index==trainers.end()) continue;
            // trainers.erase(index);
            while(j<n and i>trainers[j]){
               j++;
            }
            if(j>=n) break;
            j++;
            ans++;
        }
        return ans;
    }
};