class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0) return ans;
        string s=to_string(nums[0]);
        // if(nums.size()==1){
        //    ans.push_back(to_string(nums[0]));
        //     return ans;
        // }
        for(int i=1;i<nums.size();i++){
            long long val=(long long)nums[i]-(long long)nums[i-1];
            if(abs(val)>1){
                if(stoi(s)!=nums[i-1])
                s+="->"+to_string(nums[i-1]);
                ans.push_back(s);
                s=to_string(nums[i]);
            }
        }
        if(stoi(s)!=nums[nums.size()-1])
        s+="->"+to_string(nums[nums.size()-1]);
        ans.push_back(s);
        return ans;
    }
};