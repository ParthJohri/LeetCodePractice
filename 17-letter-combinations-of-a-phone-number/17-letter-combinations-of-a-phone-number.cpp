class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int siz=digits.length();
        vector<string> ans;
        if(siz==0)
            return ans;
        map<char,string> m ={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        switch(siz)
        {
            case 1: {string s=m[digits[0]];
                    for(int i=0;i<s.length();i++)
                        {  string nstr="";
                         nstr+=s[i];
ans.push_back(nstr);}
                    return ans;}
            case 2: {string s1=m[digits[0]];
                    string s2=m[digits[1]];
                    for(int i=0;i<s1.length();i++)
                    {   
                        for(int j=0;j<s2.length();j++)
                        {
                            string nstr="";
                            nstr+=s1[i];
                            nstr+=s2[j];
                            ans.push_back(nstr);
                        }
                    }
                    return ans;}
            case 3: {string s3=m[digits[0]];
                    string s4=m[digits[1]];
                    string s5=m[digits[2]];
                    for(auto i:s3)
                    {   
                        for(auto j:s4)
                        {for(auto k:s5)
                            {
                            string nstr="";
                            nstr+=i;
                            nstr+=j;
                            nstr+=k;
                            ans.push_back(nstr);}
                        }
                    }
                    return ans;}
            case 4: {string s6=m[digits[0]];
                    string s7=m[digits[1]];
                    string s8=m[digits[2]];
                    string s9=m[digits[3]];
                    for(auto i:s6)
                    {   
                        for(auto j:s7)
                        {for(auto k:s8)
                            {for(auto l:s9)
                            {
                                string nstr="";
                            nstr+=i;
                            nstr+=j;
                            nstr+=k;
                            nstr+=l;
                            ans.push_back(nstr);}}
                        }
                    }
                    return ans;}
            default: cout<<"wrong";
        }
        return ans;
    }
};