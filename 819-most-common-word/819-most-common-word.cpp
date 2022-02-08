class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> m;
        string delimeters="!?',;.' '";
        string temp="",word="";
        vector<string> token;
        paragraph+=" ";
        for(auto i:paragraph)
        {
            if(isalpha(i))
                temp+=tolower(i);
            else if(i=='!'||i=='?'||i==','||i==';'||i=='.'||i==' ')
                {token.push_back(temp);
                 temp="";
            continue;}
        }
        int mx=0;
        for(auto i: token)
        {
            m[i]++;
        }
        for(auto i:banned)
        {
            m[i]=0;
        }
        for(auto i:m)
        {
            if(i.second>mx&&i.first!="")
                {mx=i.second;
                word=i.first;}
        }
        return word;
    }
};