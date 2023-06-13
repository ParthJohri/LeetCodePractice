class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp=nums;
        int lis[n],lds[n];
        // lis - longest increasing subsequence
        // lds - longest descreasing subsequence
        lis[0]=1;
        for(int i=1;i<n;i++){
            lis[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
        }
        reverse(temp.begin(),temp.end());
        lds[0]=1;
        for(int i=1;i<n;i++){
            lds[i]=1;
            for(int j=0;j<i;j++){
                if(temp[i]>temp[j]){
                    lds[i]=max(lds[i],lds[j]+1);
                }
            }
        }
        reverse(lds,lds+n);
        int ans=0; // length of sequence having first strictly increasing then strictly decreasing
        for(int i=0;i<n;i++){
            if(lis[i]>1 and lds[i]>1)
            ans=max(ans,lis[i]+lds[i]-1);
        }
        int minimumNumberOfElementsToRemoveToMakeMountainArray=n-ans;
        return minimumNumberOfElementsToRemoveToMakeMountainArray;
    }
};