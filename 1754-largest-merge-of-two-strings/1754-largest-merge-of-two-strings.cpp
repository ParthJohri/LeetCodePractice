class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans="";
        int n=word1.length(),m=word2.length(),i=0,j=0;
        while(i<n && j<m){
            char ch1=word1[i],ch2=word2[j];
            if(ch1>ch2) ans+=ch1,i++;
            else if(ch1<ch2) ans+=ch2,j++;
            else{
                string s=word1.substr(i+1);
                string t=word2.substr(j+1);
                if(s>t) ans+=ch1,i++;
                else ans+=ch2,j++;
            }
        }
        while(i<n) ans+=word1[i++];
        while(j<m) ans+=word2[j++];
        return ans;
    }
};