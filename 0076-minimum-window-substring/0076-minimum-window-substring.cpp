class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0,len=INT_MAX,count,startIndex=-1,endIndex=0;
        unordered_map<char,int> m;
        string ans="";
        for(auto i:t) m[i]++;
        count=m.size();
        while(i<s.length() and j<s.length()){
            if(m.count(s[j])){
                m[s[j]]--;
                if(m[s[j]]==0) count--;
            }
            while(count==0){
                if(len>j-i+1){
                    len=j-i+1;
                    startIndex=i;
                    endIndex=j+1;
                }
                if(m.count(s[i])){
                    m[s[i]]++;
                    if(m[s[i]]>0) {
                        count++;
                    }
                } 
                i++;
            }
            j++;
        }
        if(startIndex==-1) ans="";
        else ans=s.substr(startIndex,len);
        // cout<<len<<endl;
        return ans;
    }
};