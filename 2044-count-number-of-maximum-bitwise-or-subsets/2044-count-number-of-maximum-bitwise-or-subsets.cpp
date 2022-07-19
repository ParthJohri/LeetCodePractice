class Solution {
public:
    unordered_map<int,int> m;
    int bitval(vector<int> &c){
        int ans=0;
        for(auto i:c) ans = ans | i;
        return ans;
    }
    void generate(vector<int> temp,vector<int> &nums,int x){
        for(int i=x;i<nums.size();i++){
            temp.push_back(nums[i]);
            m[bitval(temp)]++;
            generate(temp,nums,i+1);
            temp.pop_back();
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int mx=INT_MIN,count=0;
        generate(vector<int>(),nums,0);
        for(auto i:m){
            if(i.first>=mx){
                mx=i.first;
                count=i.second;
            }
        }
        return count;
    }
};