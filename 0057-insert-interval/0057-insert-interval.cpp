class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans,nans;
        bool f = true;
        if(intervals.size()==0) return {newInterval};
        for(int i=0;i<intervals.size();i++){
            if(newInterval[1]<intervals[i][0] and f){
                ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                f=false;
            }
            else if(intervals[i][1]>=newInterval[0] and f){
                int mn=min(intervals[i][0],newInterval[0]);
                int mx=max(intervals[i][1],newInterval[1]);
                ans.push_back({mn,mx});
                
                f=false;
            }
            else
            ans.push_back(intervals[i]);
        } 
        if(f) ans.push_back(newInterval);
        nans.push_back({ans[0][0],ans[0][1]});
        for(int i=1;i<ans.size();i++){
            if(nans[nans.size()-1][1]<ans[i][0])
            nans.push_back(ans[i]);
            else if(nans[nans.size()-1][1]>=ans[i][0])
            nans[nans.size()-1][1]=max(nans[nans.size()-1][1],ans[i][1]);
        }
        return nans;
    }
};