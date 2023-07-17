class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> lastindex;   
        vector<int> ans;
        int prev=-1,mx=0,length=0; // it is length okay not index
        for(int i=0;i<s.length();i++){
            lastindex[s[i]]=i;
        }
        for(int i=0;i<s.length();i++){
            mx=max(mx,lastindex[s[i]]);
            if(mx==i){
                length=mx-prev;
                prev=mx;
                ans.push_back(length);
            }
        }
        return ans;
    }
};