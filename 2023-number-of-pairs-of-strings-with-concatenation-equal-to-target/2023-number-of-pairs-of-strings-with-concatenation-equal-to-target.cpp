class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count=0;
        map<string,int> m;
        for(auto i:nums){
            m[i]++;
        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i]+nums[j]==target and j!=i)
                    count++;
            }
        }
        return count;
    }
};