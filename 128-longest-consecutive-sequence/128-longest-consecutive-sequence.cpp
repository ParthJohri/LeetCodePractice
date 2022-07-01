class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int mx=0,count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]==0){
                continue;
            }
            else if(nums[i]-nums[i-1]!=1){
                mx=max(mx,count);
                count=1;
            }
            else
                count++;
        }
        // [0,3,7,2,5,8,4,6,0,1]
        //  0 0 1 2 3 4 5 6 7 8
        return max(mx,count);
    }
};