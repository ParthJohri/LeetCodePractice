class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<int> p;
        map<int,int> m;
        for(auto i:nums){
            p.push(i);
        }
        while(k-- >0){
            m[p.top()]++;
            p.pop();
        }
        for(auto i:nums){
            if(m[i]) {ans.push_back(i); m[i]--;}
        }
        return ans;
    }
};