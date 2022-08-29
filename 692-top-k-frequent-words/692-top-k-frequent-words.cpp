class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<string,int>> v;
        vector<string> ans;
        map<string,int> m;
        for(auto i:words){
            m[i]++;
        }
        for(auto i:m){
            v.push_back({i.first,i.second});
        }
        sort(v.begin(),v.end(),[](pair<string,int> &a,pair<string,int>&b)->bool{
            if(a.second==b.second) {
                return a.first<=b.first;
            }
            return a.second>b.second;
        });
        for(auto i:v){
            k--;
            ans.push_back(i.first);
            if(k==0) break;
        }
        return ans;
    }
};