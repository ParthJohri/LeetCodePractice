class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> q;
        int j=0;
        for(int i=0;i<k;i++){
            q.push({nums[i],i});
        }
        ans.push_back(q.top().first);
        for(int i=k;i<nums.size();i++){
            q.push({nums[i],i});
            while(q.top().second<=j) q.pop();
            ans.push_back(q.top().first);
            j++;
        }
        return ans;
    }
};