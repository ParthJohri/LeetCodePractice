class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1,l2;
        l1=str1.length();
        l2=str2.length();
        if(l1==l2&&str1!=str2) return "";
        string s=str1.substr(0,__gcd(l1,l2));
        string s1="",s2="";
        while(s1.length()<l1)
        {
            s1+=s;
        }
        while(s2.length()<l2)
        {
            s2+=s;
        }
        return (s1==str1&&s2==str2?s:"");
    }
};