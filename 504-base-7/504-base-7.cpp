class Solution {
public:
    string convertToBase7(int num) {
        string s="";
        if(num==0) return "0";
        bool b=num<0;
        num=abs(num);
        while(num!=0)
        {
            s=to_string(num%7)+s;
            num/=7;
        }
        if(b)
            s="-"+s;
        return s;
    }
};