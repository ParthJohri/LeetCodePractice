class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        vector<int> ans(n,-1);
        int j=n-1;
        while(j>=0){
            st.push(nums[j]);
            j--;
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top()<=nums[i]){
                st.pop();
            }
            if(!st.empty())
                ans[i]=st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};