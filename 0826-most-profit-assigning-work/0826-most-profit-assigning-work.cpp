class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int,int> m;
        long long int ans=0;
        for(int i=0;i<difficulty.size();i++){
            m[difficulty[i]]=max(m[difficulty[i]],profit[i]);
        }
        sort(difficulty.begin(),difficulty.end());
        for(int i=1;i<difficulty.size();i++){
            m[difficulty[i]]=max(m[difficulty[i]],m[difficulty[i-1]]);
        }
        for(auto i:worker){
            int index=upper_bound(difficulty.begin(),difficulty.end(),i)-difficulty.begin()-1;
            if(index<0) continue;
            ans+=m[difficulty[index]];
        }
        return ans;
    }
};