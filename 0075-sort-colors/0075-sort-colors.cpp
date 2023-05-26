class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros=0,i=0,twos=nums.size()-1;
        while(i<=twos){
            if(nums[i]==0){
                swap(nums[zeros],nums[i]);
                i++;
                zeros++;
            }
            else if(nums[i]==2){
                swap(nums[twos],nums[i]);
                twos--;
            }
            else 
            {
                i++;
            }
        }
    }
};