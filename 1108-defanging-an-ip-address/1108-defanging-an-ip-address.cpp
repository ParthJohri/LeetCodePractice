class Solution {
public:
    string defangIPaddr(string address) {
        string str="";
        for(auto i: address)
        {
            if(i=='.')
                {str+="[.]"; 
                continue;}
            str+=i;
        }
    return str;
    }
};