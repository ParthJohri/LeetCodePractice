class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> x,y;
        for(auto i:arr) x[i]++;
        for(auto i:x) y[i.second]++;
        for(auto i:y){
            if(i.second>1) return false;
        }
        return true;
    }
};