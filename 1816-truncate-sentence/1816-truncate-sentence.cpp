class Solution {
public:
    string truncateSentence(string s, int k) {
        string str="",newstr="";
        for(auto i: s)
        {
            if(isspace(i))
            {
                newstr+=" ";  
                k--;
                if(k==0)
                    return newstr.substr(0,newstr.length()-1);
            }
            else
            {
                newstr+=i;
            }
        }
        return newstr;
    }
};