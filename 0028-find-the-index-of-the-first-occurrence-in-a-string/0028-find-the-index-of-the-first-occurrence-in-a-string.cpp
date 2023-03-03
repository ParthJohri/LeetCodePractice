class Solution {
public:
    int strStr(string haystack, string needle) {
        auto id=haystack.find(needle);
        if(id!=string::npos) return id;
        return -1;
    }
};