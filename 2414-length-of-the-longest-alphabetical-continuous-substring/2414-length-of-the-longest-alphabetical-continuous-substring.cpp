class Solution {
public:
    int longestContinuousSubstring(string s) {
        string check="abcdefghijklmnopqrstuvwxyz";
        int j=0,count=1,cc=1;
        while(j<s.length()-1){
            if(s[j+1]-s[j]==1){
                cc++;
            }
            else{
                count=max(count,cc);
                cc=1;
            }
            j++;
        }
        count=max(count,cc);
        return count;
    }
};