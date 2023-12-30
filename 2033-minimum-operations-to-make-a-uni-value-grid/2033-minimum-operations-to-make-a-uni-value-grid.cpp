class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int ans=0;
        vector<int> temp;
        for(auto i:grid){
            for(auto j:i){
                temp.push_back(j);    
            }
        }
        sort(temp.begin(),temp.end());
        int median=temp[temp.size()/2];
        for(auto i:temp){
            int diff=abs(median-i);
            if(diff%x!=0) return -1;
            ans+=diff/x;
        }
        return ans;
    }
};