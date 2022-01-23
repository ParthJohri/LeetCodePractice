class Solution {
public:
    bool palin(string s)
    {
        string str=s;
        reverse(s.begin(),s.end());
        return str==s;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto i: words)
          {  if(palin(i))
                return i;}
        return "";
    }
};