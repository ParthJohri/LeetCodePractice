class Solution {
public:
    int convert(string& s){
        int h=0,m=0;
        string hh="",mm="";
        bool flag=false;
        for(auto i:s){
            if(i==':'){
                flag=true;
                continue;
            }
            if(flag){
                mm+=i;
            }
            else{
                hh+=i;
            }
        }
        h=stoi(hh);
        m=stoi(mm);
        return h*60+m;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for(auto i:timePoints){
            v.push_back(convert(i));
        }
        // Think of clockwise
        sort(v.begin(),v.end());
        v.push_back(v[0]+24*60);
        int ans=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            int d=v[i+1]-v[i];
            ans=min(ans,d);
        }
        return ans;
    }
};