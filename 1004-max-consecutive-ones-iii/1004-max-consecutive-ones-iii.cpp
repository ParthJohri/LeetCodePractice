class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0,left=0,right=0,mf=0,id=0;
        map<int,int> m;
        vector<int> v;
        int x=0;
        for(right=0;right<nums.size();right++){
            m[nums[right]]++;
           if(nums[right]==0){
               v.push_back(right);
           }
           if(m[0]>k){
               m[0]--;
               left=v[x++]+1;
           }
            ans=max(ans,right-left+1);
        }
        cout<<right<<" "<<left<<endl;
        return ans;
    }
};