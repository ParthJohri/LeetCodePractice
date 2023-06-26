class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        int left=1,right=n,i=0;
        while(left<=right){
            if(k%2==0){
                ans[i]=left++;
            }
            else{
                ans[i]=right--;
            }
            i++;
            if(k!=1) k--;
        }
        return ans;
    }
};