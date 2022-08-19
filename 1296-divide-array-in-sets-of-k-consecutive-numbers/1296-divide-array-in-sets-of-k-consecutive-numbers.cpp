class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> av;
        sort(nums.begin(),nums.end());
        for(auto i:nums) av[i]++;
        for(int i=0;i<nums.size();i++){
            if(av[nums[i]]<=0) continue;
            else if(av[nums[i]]>0){
                av[nums[i]]--;
                for(int j=1;j<k;j++){
                    if(av[nums[i]+j]>0){
                        av[nums[i]+j]--;
                    }
                    else 
                        return false;
                }
            }
            else 
                return false;
        }
        return true;
    }
};