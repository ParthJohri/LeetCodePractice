class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        int left=0,right=0,n=nums.size();
        multiset<int> s;
        while(right<n){
            s.insert(nums[right]);  
            int mx=s.size()>0?*(s.rbegin()):0;
            int mn=s.size()>0?*(s.begin()):0;
            while(mx-mn>2){
                s.erase(s.find(nums[left]));
                mx=*(s.rbegin());
                mn=*(s.begin());
                left++;
            }
            ans+=right-left+1;
            right++;
        }
        return ans;
    }
};