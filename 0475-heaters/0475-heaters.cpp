class Solution {
public:
    bool check(vector<int>& houses, vector<int>& heaters,int radius){
        vector<pair<int,int>> v;
        for(auto i:heaters){
            v.push_back({i-radius,i+radius});
        }
        int i=0,j=0,h=houses.size(),he=v.size();
        while(i<h and j<he){
            if(houses[i]>=v[j].first and houses[i]<=v[j].second) i++;
            else j++;
        }
        return i==h;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int start=0,end=INT_MAX,ans=0;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        if(houses==heaters) return 0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(check(houses,heaters,mid)){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};