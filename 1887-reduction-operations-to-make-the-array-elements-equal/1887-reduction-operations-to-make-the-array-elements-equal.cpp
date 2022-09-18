class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int count=0;
        vector<int> s;
        map<int,int> m,fr; 
        for(auto i:nums){
            if(!fr.count(i)) s.push_back(i);
            fr[i]++;
        }
        int pos=1;
        sort(s.begin(),s.end());
        for(auto i:s){
            m[i]=pos++;
        }
        for(int i=s.size()-1;i>=1;i--){
            count+=fr[s[i]]*(m[s[i]]-m[s[0]]);
        }
        return count;
    }
};