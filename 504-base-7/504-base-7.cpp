class Solution {
public:
    string convertToBase7(int num) {
//         Decimal to Other Base System
//         Step 1 − Divide the decimal number to be converted by the value of the new base.

//         Step 2 − Get the remainder from Step 1 as the rightmost digit (least significant digit) of new base number.

//         Step 3 − Divide the quotient of the previous divide by the new base.

//         Step 4 − Record the remainder from Step 3 as the next digit (to the left) of the new base number.
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