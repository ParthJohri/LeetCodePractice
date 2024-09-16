class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int,int>> v;
        for(auto i:timePoints){
            string hour = i.substr(0,2);
            string minute = i.substr(3,2);
            int h = stoi(hour), m = stoi(minute);
            v.push_back({h,m});
        }
            sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
                if(a.first==b.first) return a.second<b.second;
                return  a.first<b.first;
            });
            int ans=INT_MAX;
            v.push_back({v[0].first+24,v[0].second});
            for(int i=0;i<v.size()-1;i++)
            {
                int hd=abs(v[i+1].first-v[i].first)*60;
                int md=v[i+1].second-v[i].second;
                ans=min(ans,hd+md);
            }
            return ans;
    }
};