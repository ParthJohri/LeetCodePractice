class Solution {
public:
    int longestContinuousSubstring(string s) {
        int i=0,count=1,cc=1;
        while(i<s.length()-1){
            if(s[i+1]-s[i]==1){
                cc++;
            }
            else{
                count=max(count,cc);
                cc=1;
            }
            i++;
        }
        count=max(count,cc);
        return count;
    }
};