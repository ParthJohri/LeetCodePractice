class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>> v;
        map<char,int> m;
        for(auto i:s){
            m[i]++;
        }
        for(auto i:m){
            v.push_back({i.first,i.second});
        }
        sort(v.begin(),v.end(),[](pair<char,int> &a,pair<char,int> &b)->bool{
            if(a.second==b.second) return false;
            return a.second>b.second;
        });
        string ans="";
        for(auto i:v){
            int k=i.second;
            if(k>0){
                while(k--)
                ans+=i.first;
            }  
        }
        return ans;
    }
};