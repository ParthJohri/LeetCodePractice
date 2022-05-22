class Solution {
public:
    string addStrings(string num1, string num2) {
       int n1=num1.length();
       int n2=num2.length();
       int v=max(n1,n2);
       if(v-n1>0)
       {
           int c=v-n1;
           while(c--)
           {
               num1="0"+num1;
           }
       }
       else 
        {
            int c2=v-n2;
           while(c2--)
           {
               num2="0"+num2;
           }
        }
        string s;
        int sum=0,car=0;
        for(int i=v-1;i>=0;i--)
        {
             sum=(num2[i]-'0'+num1[i]-'0'+car);
             car=sum/10;
             sum=sum%10;
             s=to_string(sum)+s;
        }
        if(car!=0)
        s=to_string(car)+s;
        return s;
    }
};