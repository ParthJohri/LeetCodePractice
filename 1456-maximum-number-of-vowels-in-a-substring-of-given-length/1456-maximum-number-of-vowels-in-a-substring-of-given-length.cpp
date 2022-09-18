class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0,ans=0;
        map<char,int> m={
            {'a',1},
            {'e',1},
            {'i',1},
            {'o',1},
            {'u',1}
        };
        for(int i=0;i<k;i++){
          if(m.count(s[i])){
              count++;
          }  
        }
        ans=max(count,ans);
        for(int i=k;i<s.length();i++){
            if(m.count(s[i-k])){
                count--;
            }
            if(m.count(s[i])){
                count++;
            }
            ans=max(count,ans);
        }
        return ans;
    }
};