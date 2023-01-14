class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        multiset<pair<int,int>> s;
        for(auto i:arr){
            s.insert({abs(i-x),i});
        }
        for(auto i:s){
            ans.push_back(i.second);
            k--;
            if(k==0) break;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};