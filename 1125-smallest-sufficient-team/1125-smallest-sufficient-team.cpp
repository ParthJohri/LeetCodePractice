class Solution {
public:
    int dp[1<<16][64];
    bool choice[1<<16][64];
    int rmask;
    int recur(vector<int>&peeps,int index,int mask){
        if(mask==rmask) return 0;
        if(index==peeps.size()) return 1000;
        if(dp[mask][index]!=-1) return dp[mask][index];
        int takeit=1+recur(peeps,index+1,mask|peeps[index]);
        int nottakeit=recur(peeps,index+1,mask);
        if(takeit<nottakeit)
            choice[mask][index]=1;
        return dp[mask][index]=min(takeit,nottakeit);
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string,int> m;
        int n=req_skills.size();
        int required_mask=(1<<n)-1;
        
        for(int i=0;i<n;i++){
            m[req_skills[i]]=i;
        }
        vector<int> peeps;
        for(auto i:people){
            int h=0;
            for(auto s:i){
                h|=(1<<m[s]);
            }
            peeps.push_back(h);
        }
        
        rmask=required_mask;
        memset(dp,-1,sizeof(dp));
        memset(choice,0,sizeof(choice));
        
        recur(peeps,0,0);
        
        int mask=0;
        vector<int> ans;
        for(int i=0;i<peeps.size();i++){
            if(choice[mask][i]){
                mask|=peeps[i];
                ans.push_back(i);
            }
            if(mask==required_mask) break;
        }
        return ans;
    }
};