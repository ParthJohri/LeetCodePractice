class Solution {
public:
    int minimumSubarrayLength(vector<int>& n, int k) {
        int s=0,ans=INT_MAX;
        for(int i=0;i<n.size();i++){
            s=n[i];
            if(s>=k) ans=1;
            for(int j=i+1;j<n.size();j++){
                s|=n[j];
                if(s>=k) {
                    ans=min(ans,j-i+1);
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};