class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        // 1,3,6,8
        // pos = 1, index = 0;
        // pos = 5, index = 2;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<long long> ans;
        for(auto i:queries){
            int index=upper_bound(nums.begin(),nums.end(),i)-nums.begin()-1;
            int leftcount=index+1,rightcount=n-index-1;
            long long val=0;
            cout<<index<<endl;
            if(index==-1) {
                val=prefix[n-1]-i*1ll*n;
            }
            else{
                val=i*1ll*leftcount-prefix[index];
                val+=(prefix[n-1]-prefix[index])-i*1ll*rightcount;
            }
            ans.push_back(val);
        }
        return ans;
    }
};