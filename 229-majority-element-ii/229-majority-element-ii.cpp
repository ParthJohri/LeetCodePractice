class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int x=nums.size()/3,y=x;
        if(nums.size()==1){
            ans.push_back(nums[0]);
            return ans;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                x--;
            }
            else{
                x--;
                if(x<0){
                    ans.push_back(nums[i]);
                }
                x=y;
            }
        }
        if(nums[nums.size()-1]==nums[nums.size()-2] or y==0){
            x--;
            if(x<0){
                ans.push_back(nums[nums.size()-1]);
            }
        }
        return ans;
    }
};