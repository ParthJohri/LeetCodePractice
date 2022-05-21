class Solution {
public:
    int minimumMoves(string s) {
     int count=0;
      s+="OO";
       for(int i=0;i<s.length()-2;i++)
       {
           if(s[i]=='X')
           {
               ++count;
               i+=2;
           }
       }
       return count;
    }
};