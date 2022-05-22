class Solution {
public:
    string add(string s1,string s2)
    {
        string ans="";
        int v1=s1.length()-1,v2=s2.length()-1,c=0,a=0;
        while(v1>=0||v2>=0)
        {
            if(v1>=0)
                a+=s1[v1--]-'0';
            if(v2>=0)
                a+=s2[v2--]-'0';
            a+=c;
            c=a/10;
            a=a%10;
            ans=to_string(a)+ans;
            a=0;
        }
        if(c!=0)
            ans=to_string(c)+ans;
        return ans;
    }
    string multiply(string num1, string num2) {
        string ans="0";
        int v=num2.length()-1;
        if(num1 == "0"|| num2 == "0")
            return "0";
        if(num1.length()>=num2.length())
        {
            for(int i=num2.length()-1;i>=0;i--)
            {
                string temp="";
                v=num2.length()-1;
                while(abs(v-i)>0)
                    {
                        temp="0"+temp;
                        v--;
                    }
                int v=0,c=0;
                for(int j=num1.length()-1;j>=0;j--)
                {
                    v=(num1[j]-'0')*(num2[i]-'0')+c;
                    c=v/10;
                    v=v%10;
                    temp=to_string(v)+temp;
                    v=0;
                }
                if(c!=0)
                    temp=to_string(c)+temp;
                cout<<temp<<" ";
                ans=add(temp,ans);
            }
        }
        else
        {
            for(int i=num1.length()-1;i>=0;i--)
            {
                string temp="";
                v=num1.length()-1;
                while(abs(v-i)>0)
                    {
                        temp="0"+temp;
                        v--;
                    }
                int v=0,c=0;
                for(int j=num2.length()-1;j>=0;j--)
                {
                    v=(num2[j]-'0')*(num1[i]-'0')+c;
                    c=v/10;
                    v=v%10;
                    temp=to_string(v)+temp;
                    v=0;
                }
                if(c!=0)
                    temp=to_string(c)+temp;
                cout<<temp<<" ";
                ans=add(temp,ans);
            }
        }
        return ans;
    }
};