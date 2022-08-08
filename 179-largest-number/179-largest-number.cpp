class Solution {
public:
    bool static cmp(string a,string b){
        if(a==b) return true;
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        int count=0;
        for(auto i:nums){
            if(i==0)
                ++count;
            temp.push_back(to_string(i));
        }
        if(count==nums.size()) return "0";
        sort(temp.begin(),temp.end(),cmp);
        string ans="";
        for(auto i:temp){
            ans+=i;
        }
        return ans;
    }
};