class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        if(nums.size()==1) return nums[0];
        while(left<=right){
            int mid=(left+(right-left/2));
            if(mid%2==0 and nums[mid]==nums[mid+1] or mid%2 and nums[mid]==nums[mid-1]){
                left=mid+1;
            }
            else
                right=mid-1;
        }
        cout<<left<<" "<<right<<endl;
        return nums[left];
    }
};