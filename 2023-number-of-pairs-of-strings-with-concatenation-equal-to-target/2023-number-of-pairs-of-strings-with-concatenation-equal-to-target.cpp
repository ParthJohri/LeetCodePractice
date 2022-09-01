class Solution {
public:
    int numOfPairs(vector<string>& nums, string target){
        int count=0;
        unordered_map<string,int> m;
        for(auto i:nums){
            m[i]++;
        }
        for(int i=0;i<target.size();i++){
           string s1=target.substr(0,i);
           string s2=target.substr(i,target.size());
            if(s1==s2)
                count+=m[s1]*(m[s2]-1);
            else 
                count+=m[s1]*m[s2];
        }
        // 7777
        // 7, 777
        // 77, 77
        // 777,7
        // 7777, 
        return count;
    }
};