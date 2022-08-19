class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int,int> m;
        int mx=0;
        m[0]=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==key){
                m[nums[i+1]]++;
                if(m[mx]<=m[nums[i+1]]){
                mx=nums[i+1];
                }
            }
        }
        return mx;
    }
};