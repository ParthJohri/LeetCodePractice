class Solution {
public:
    int lowerbound(vector<vector<int>>& items, int& val){
        int start=0,end=items.size()-1,ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(items[mid][0]<=val){
                ans=max(ans,items[mid][1]);
                start=mid+1;
            }
            else
                end=mid-1;
        }
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector<int> ans(queries.size(),0);
        for(int i=1;i<items.size();i++){
            items[i][1]=max(items[i][1],items[i-1][1]);
        }
        for(int i=0;i<queries.size();i++){
            ans[i]=lowerbound(items,queries[i]);
        }
        return ans;
    }
};