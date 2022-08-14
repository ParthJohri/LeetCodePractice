class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        while(num!=0){
            string t=to_string(num);
            if(num>=1000){
                ans+='M';
                num-=1000;
            }
            else if(t[0]=='9'){
                if(t.length()==3){
                    ans+="CM";
                num-=900;}
                else if(t.length()==2){
                    ans+="XC";
                num-=90;}
                else {
                    ans+="IX";
                num-=9;}
            }
            else if(t[0]=='4'){
                if(t.length()==3){
                    ans+="CD";
                    num-=400;
                }
                else if(t.length()==2){
                    ans+="XL";
                    num-=40;
                }
                else{
                    ans+="IV";
                    num-=4;
                }
            }
            else if(num>=500 and num<1000){
                ans+="D";
                num-=500;
            }
            else if(num>=100 and num<500){
                ans+="C";
                num-=100;
            }
            else if(num>=50 and num<100){
                ans+="L";
                num-=50;
            }
            else if(num>=10 and num<50){
                ans+="X";
                num-=10;
            }
            else if(num>=5 and num<10){
                ans+="V";
                num-=5;
            }
            else{
                ans+="I";
                num-=1;
            }
        }
        return ans;
    }
};