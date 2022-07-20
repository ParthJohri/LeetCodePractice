class Solution {
public:
    // void generate(vector<int> &nums, vector<int> temp, set<vector<int>> &s, int start){
    //     if(start==nums.size()){        
    //         s.insert(temp);
    //         return;
    //     }
    //     temp.push_back(nums[start]);
    //     generate(nums,temp,s,start+1);
    //     temp.pop_back();
    //     generate(nums,temp,s,start+1);
    // }
    
    void generate(vector<int> &nums, vector<int> temp, set<vector<int>> &s, int start){
        s.insert(temp);
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            generate(nums,temp,s,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        generate(nums,vector<int>(),s,0);
        for(auto i:s){
            v.push_back(i);
        }
        return v;
    }
};