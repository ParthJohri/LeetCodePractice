class Solution {
public:
    // This problem is the best example of how functions 
    // are in Mathematics, no element matches 2 elements and
    // no 2 elements have same input
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_map<char,char> n;
        // First I created a map which stores 
        // the unique values like example - 1
        // e - a, g - d
        for(int i=0;i<s.length();i++)
        {
            if(m[s[i]]=='\0')
            m[s[i]]=t[i];
        }
        // This is for the second relation
        // badc, baba
        // Here, also I did the same
        // b-b, a-a (only the first character)
        for(int i=0;i<t.length();i++)
        {
            if(n[t[i]]=='\0')
            n[t[i]]=s[i];
        }
        // Now I am reforming the string using the map 
        // values too check if there is any character that
        // is not following the constraints
        string str="",nstr="";
        for(auto i:s)
        {
            str+=m[i];
        }
        for(auto i:t)
        {
            nstr+=n[i];
        }
        // Checking if both the new reformed
        // strings matches with the input 
        // If not then there is some characters
        // repititive 
        return str==t&&nstr==s;
    }
};
// Input
// "egg"
// "add"
// "foo"
// "bar"
// "paper"
// "title"
// "hello"
// "johri"
// "badc"
// "baba"
// "bbbaaaba"
// "aaabbbba"