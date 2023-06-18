class Solution {
public:
    vector<int> stackPreviousSmaller(vector<int>&heights){
        int n=heights.size();
        vector<int>prevSmaller(n,-1);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() and heights[s.top()]>=heights[i]){
                    s.pop();
            }
            if(s.empty()){
                prevSmaller[i]=-1;//start of array
            }
            else{
                prevSmaller[i]=s.top();
            }
            s.push(i);//pushing index of elements
        }
        return prevSmaller;
    }
    vector<int> stackNextSmaller(vector<int>&heights){
        int n=heights.size();
        vector<int> nextSmaller(n,-1);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                nextSmaller[i]=n;//end of array
            }
            else{
                nextSmaller[i]=s.top();
            }
            s.push(i);//pushing index of elements
        }
        return nextSmaller;
    }
    int maxSumMinProduct(vector<int>& nums) {
        long long ans=0,mod=1e9+7,n=nums.size();
        vector<long long> prefixSum(n+1,0);
        prefixSum[0]=nums[0];
        for(int i=1;i<=n;i++){
            prefixSum[i]=nums[i-1]+prefixSum[i-1];
        }
        vector<int> nextSmaller=stackNextSmaller(nums);
        vector<int> prevSmaller=stackPreviousSmaller(nums);
        for(int i=0;i<n;i++){
            int l=prevSmaller[i];
            int r=nextSmaller[i];
            long long val=(prefixSum[r]-prefixSum[l+1])*1ll*(nums[i]);
            ans=max(ans,val);
        }
        return ans%mod;
    }
};