class Solution {
public:
    static bool cmp(vector<int>& pair1,vector<int>& pair2){
        return pair1[1]<pair2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int c=1,i=0,j=1,n=pairs.size(),prev=pairs[0][1];
        while(j<n){
            if(pairs[i][1]<pairs[j][0]){
                i=j;
                ++c;
            }
            j++;
        }
        return c;
    }
};