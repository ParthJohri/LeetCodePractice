class Solution {
public:
    string largestOddNumber(string num) {
       int x=0;
        for(int i=num.length()-1;i>=0;i--)
       {
           if((num[i]-'0')%2!=0)
               return num.substr(0,num.length()-x);
           else
               x++;
       }
        return "";
    }
};