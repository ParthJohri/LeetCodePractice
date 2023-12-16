class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m;
        for(auto i:s) m[i]++;
        for(auto i:t) m[i]--;
        for(auto i:m){
            if(i.second!=0) return false;
        }
        return true;
    }
};