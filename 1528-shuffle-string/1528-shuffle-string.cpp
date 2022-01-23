class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string str=s;
        int x=0;
        for(auto i: indices)
            str[i]=s[x++];
        return str;
    }
};