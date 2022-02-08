class Solution {
public:
    int sumdigit(string &str)
    {
        int s=0;
        for(auto i: str)
        {
            s+=i-'0';
        }
        return s;
    }
        int getLucky(string s, int k) {
        string str="";
        int num=0;
        for(char i: s)
        {
            int ch=i-'a'+1;
            str+=to_string(ch);
        }
        while(k--)
        {
            num=sumdigit(str);
            str=to_string(num);
        }
        return num;
    }
};