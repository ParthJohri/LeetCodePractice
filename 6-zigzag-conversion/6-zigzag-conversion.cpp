class Solution {
public:
    string convert(string s, int numRows) {
        string ans="";
        vector<string> v(numRows,"");
        int x=0;
        bool b=true;
        if(numRows==1) return s;
        for(int i=0;i<s.length();i++)
        {
            if(x==0) {x=0; b=true;}
            if(x<numRows && b==true)
            {
                v[x]+=s[i];
                x++;
                cout<<x<<" ";
                continue;
            }
            else if(x==numRows && b==true)
            {
                x-=2;
                b=false;
                --i;
            }
            else if(x>0)
            {
                cout<<x<<"\t";
                v[x--]+=s[i];
            }
        }
        for(auto i:v)
            {cout<<i<<"\t";ans+=i;}
        return ans;
    }
};