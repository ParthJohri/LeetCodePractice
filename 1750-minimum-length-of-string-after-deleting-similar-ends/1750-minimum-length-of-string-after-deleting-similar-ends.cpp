class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                break;
            }
            else{
                char c=s[i];
                while(c==s[i] and i<=j) i++;
                while(c==s[j] and j>=i) j--;
            }
        }
        return j-i+1;
    }
};