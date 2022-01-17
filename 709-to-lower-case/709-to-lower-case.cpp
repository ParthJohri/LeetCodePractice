class Solution {
public:
    string toLowerCase(string s) {
        string str="";
        for(auto i:s)
        {
            if(i>='A'&&i<='Z')
             i=i+32;
             str+=i;
        }
            return str;
    }
};