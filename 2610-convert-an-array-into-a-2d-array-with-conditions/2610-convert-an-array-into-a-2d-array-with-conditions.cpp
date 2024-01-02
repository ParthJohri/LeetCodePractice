class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int m[201];
        memset(m,0,sizeof(m));
        for(auto i:nums) m[i]++;
        while(true){
            vector<int>temp;
            bool flag=true;
            for(int i=1;i<=200;i++){
                if(m[i]==0) continue;
                temp.push_back(i);
                m[i]--;
                flag=false;
            }
            if(flag) break;
            ans.push_back(temp);
        }
        return ans;
    }
};