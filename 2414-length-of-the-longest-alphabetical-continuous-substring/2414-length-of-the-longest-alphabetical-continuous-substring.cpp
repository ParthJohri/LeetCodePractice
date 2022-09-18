class Solution {
public:
    int longestContinuousSubstring(string s) {
        string check="abcdefghijklmnopqrstuvwxyz";
        map<char,int> m;
        int count=1,cc=0,temp=1;
        for(auto i:check){
            m[i]=cc++;
        }
        s+=" ";
        for(int i=0;i<s.length()-1;i++){
            if(m[s[i+1]]-m[s[i]]==1){
                temp++;
            }
            else{
                count=max(count,temp);
                temp=1;
            }
        }
        count=max(count,temp);
        return count;
    }
};