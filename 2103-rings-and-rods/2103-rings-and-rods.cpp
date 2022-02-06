class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int,string> v;
        int count=0;
        for(int i=1;i<rings.length();i+=2)
        {
            int bar=rings[i]-'0';
            string val="";
            if(rings[i-1]=='B')
                val+="B";
            else if(rings[i-1]=='R')
                val+="R";
            else
                val+="G";
            v[bar]+=val;
        }
        for(auto i:v)
        {
            bool flag1,flag2,flag3; 
            flag1=flag2=flag3=false;
            for(auto j: i.second)
            {
                if(j=='B')
                    flag1=true;
                else if(j=='G')
                    flag2=true;
                else if(j=='R')
                    flag3=true;
            }
            if(flag1&&flag2&&flag3)
                ++count;
        }
        return count;
    }
};