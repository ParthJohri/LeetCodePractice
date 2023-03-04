class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum=0,sum2=0,n=nums1.size(),m=nums2.size();
        for(auto i:nums1) sum+=i;
        for(auto i:nums2) sum2+=i;
        if(sum<sum2 and m>n*6 or sum>sum2 and n>m*6)
        return -1;
        int ab=abs(sum-sum2),ans=0;
        if(sum>sum2){
            swap(nums1,nums2);
        }
        priority_queue<int> mx(nums2.begin(),nums2.end());
        priority_queue<int,vector<int>,greater<int>> mn(nums1.begin(),nums1.end());
        // nums1<nums2
        while(ab>0){
            ans++;
            if(mn.empty() or !mx.empty() and mx.top()-1>6-mn.top()){
               ab-=mx.top()-1;
               mx.pop();
            }
            else{
              ab-=6-mn.top();
              mn.pop();
            }
        }
        return ans;
    }
};