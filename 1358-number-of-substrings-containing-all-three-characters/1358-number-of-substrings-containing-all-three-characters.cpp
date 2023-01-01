class Solution {
public:
    int numberOfSubstrings(string s) {
      map<char,int> m;
      int ans=0,j=0,n=s.length();
      for(int i=0;i<s.length();i++){
          m[s[i]]++;
          while(m['a']>0 && m['b']>0 && m['c']>0) {
              ans+=n-i;
              m[s[j]]--;
              j++;
        }
      }
      return ans;
    }
};