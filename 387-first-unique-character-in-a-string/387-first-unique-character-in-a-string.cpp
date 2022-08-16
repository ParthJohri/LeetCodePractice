class Solution {
public:
    int firstUniqChar(string s) {
        int c[26]={0};
        for(auto i:s){
            c[i-97]++;
        }
        for(int i=0;i<s.length();i++){
            if(c[s[i]-97]==1)
                return i;
        }
        return -1;
    }
};