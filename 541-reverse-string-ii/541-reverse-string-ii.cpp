class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.length();i+=2*k)
        {
            if(i+k<=s.length()-1)
            {
                reverse(i+s.begin(),i+k+s.begin());
            }
            else
            {
                reverse(i+s.begin(),s.end());
            }
        }
        return s;
    }
};