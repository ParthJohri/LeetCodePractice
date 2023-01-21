class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int i=0,j=1,ans=0;
        map<pair<int,int>,int> m;
        sort(nums.begin(),nums.end());
        while(i<j and j<nums.size()){
            if(nums[j]-nums[i]==k and !m.count({nums[j],nums[i]}) and !m.count({nums[i],nums[j]})) {++ans;m[{nums[j],nums[i]}]++;m[{nums[i],nums[j]}]++;j++;i++;}
            else if(nums[j]-nums[i]>k) {
                ++i;
                if(i==j)
                ++j;
            }
            else
                ++j;
        }
        return ans;
    }
};