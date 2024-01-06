class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>lis.back()){
                lis.push_back(nums[i]);
            }
            else{
                int id=lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
                if(id!=nums.size() and id!=-1)
                    lis[id]=nums[i];
            }
        }
        return lis.size();
    }
};