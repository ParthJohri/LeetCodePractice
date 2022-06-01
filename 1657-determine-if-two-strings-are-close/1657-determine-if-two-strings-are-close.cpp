class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;
        map<char,int> m1,m2;
        map<int,int> m3;
        for(int i=0;i<word1.length();i++)
        {
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        for(auto i:m1)
        {
            m3[i.second]++;
            cout<<m3[i.second];
        }
        for(auto i:m2)
        {
            if(m1[i.first]==0)
                return false;
            m3[i.second]--;
            cout<<m3[i.second];
        }
        for(auto i:m3)
        {
            if(i.second!=0)
                return false;
        }
        return true;
    }
};