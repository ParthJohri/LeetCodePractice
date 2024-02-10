class Solution {
public:
    int expand(string&s,int i,int j){
        int count=0;
        while(i>=0 and j<s.size()){
            if(s[i]==s[j]){
                i--;
                j++;
                count++;
            }
            else break;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            ans+=expand(s,i,i); // odd length
            ans+=expand(s,i,i+1); // even length
        }
        return ans;
    }
};