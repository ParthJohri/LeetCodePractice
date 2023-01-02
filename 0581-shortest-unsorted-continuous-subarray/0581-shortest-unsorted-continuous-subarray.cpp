class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr=nums;
        sort(nums.begin(),nums.end());
        int start=0,end=0;
        bool flag=true;
        for(int i=0;i<nums.size();i++){
            if(arr[i]==nums[i]) continue;
            else if(flag) start=i,flag=false;
            else end=i;
        }
        return end==0?0:end-start+1;
    }
};