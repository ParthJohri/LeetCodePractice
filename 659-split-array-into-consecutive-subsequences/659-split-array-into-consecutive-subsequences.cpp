class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> av,vac;
        for(auto i:nums){
            av[i]++;
        }
        for(int i=0;i<nums.size();i++){
            if(av[nums[i]]<=0) continue;
            else if(vac[nums[i]]>0){
                av[nums[i]]--;
                vac[nums[i]]--;
                vac[nums[i]+1]++;
            }
            else if(av[nums[i]]>0 and av[nums[i]+1]>0 and av[nums[i]+2]>0){
                av[nums[i]]--;
                av[nums[i]+1]--;
                av[nums[i]+2]--;
                vac[nums[i]+3]++;
            }
            else 
                return false;
        }
        return true;
    }
};