class Solution {
public:
    static bool cmp(vector<int>& pair1,vector<int>& pair2){
        return pair1[1]<pair2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int c=1,i=0,j=1,n=pairs.size(),prev=pairs[0][1];
        while(j<n){
            if(prev<pairs[j][0]){
                prev=pairs[j][1];
                ++c;
            }
            j++;
        }
        return c;
    }
};