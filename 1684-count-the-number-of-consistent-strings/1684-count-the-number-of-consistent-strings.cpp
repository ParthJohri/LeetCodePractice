class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int allow[26]={0};
        int count=0,check=0;
        for(auto i: allowed)
            allow[i-'a']++;


        for(auto s:words)
        {s+=" ";
            for(int j=0;j<s.length()-1;j++)
            {
                if(allow[s[j]-'a']==0&&s[j]!=s[j+1])
                   { ++check;
                    break;}
            }
         if(check==0)
             {cout<<s<<endl;count++;}
         check=0;
        }
        
        return count;
    }
};