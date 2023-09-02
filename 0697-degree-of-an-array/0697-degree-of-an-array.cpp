class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> count, first;
        int degree=0,ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(first.find(nums[i])==first.end()) first[nums[i]]=i;
            count[nums[i]]++;
            if(++count[nums[i]]>degree){
                degree=count[nums[i]];
                ans=i-first[nums[i]]+1;
            }
            else if(count[nums[i]]==degree){
                ans=min(ans,i-first[nums[i]]+1);
            }
        }
        return ans;
    }
};