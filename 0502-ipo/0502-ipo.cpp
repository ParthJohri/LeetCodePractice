class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        for(int i=0;i<profits.size();i++){
            v.push_back({profits[i],capital[i]});
        }
        sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b){
            if(a.second==b.second) return a.first>b.first;
            return a.second<b.second;
        });
        priority_queue<int> p;
        int ans=w,x=0;
        while(k--){
            while(x<profits.size() and ans>=v[x].second){
                p.push(v[x++].first);
            }
            if(p.empty()) break;
            ans+=p.top();
            p.pop();
        }
        return ans;
    }
};