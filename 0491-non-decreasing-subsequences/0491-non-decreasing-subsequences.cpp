class Solution {
public:
    void generatesequences(vector<int>a, vector<vector<int>>&subsequences,vector<int>&nums,int index){
        if(index==nums.size()){
            subsequences.push_back(a);
            return;
        }
        generatesequences(a,subsequences,nums,index+1);
        a.push_back(nums[index]);
        generatesequences(a,subsequences,nums,index+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> subsequences,ans;
        vector<int> a;
        set<vector<int>> s;
        generatesequences(a,subsequences,nums,0);
        for(auto v:subsequences){
            bool f=true;
            int sz=v.size();
            for(int i=0;i<sz-1;i++){
                if(v[i]>v[i+1]){
                    f=false;
                break;}
            }
            if(f and v.size()>=2) s.insert(v);
        }
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};