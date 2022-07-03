class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int t[1001]={0};
        for(auto i:arr) t[i]++;
        for(auto i:target) t[i]--;
        for(auto i:t) {
            if(i!=0) return false;
        }
        return true;
    }
};