class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx_element=INT_MIN;
        for(auto &i:nums) mx_element=max(mx_element,i);
        int ans=0,length=0;
        for(auto &i:nums){
            if(i==mx_element){
                ++length;
                ans=max(ans,length);
            }
            else{
                length=0;
            }
        }
        return ans;
    }
};