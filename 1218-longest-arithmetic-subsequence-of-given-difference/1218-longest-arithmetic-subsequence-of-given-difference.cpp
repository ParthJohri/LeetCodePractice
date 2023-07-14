class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int,int> m;
        int ans=1;
        for(auto i:arr){
            if(m.count(i-d)){
                m[i]=m[i-d]+1;
            }
            else m[i]=1;
        }
        for(auto i:m){
            ans=max(ans,i.second);
        }
        return ans;
    }
};