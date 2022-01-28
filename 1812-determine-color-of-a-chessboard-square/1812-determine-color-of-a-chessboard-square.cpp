class Solution {
public:
    bool squareIsWhite(string str) {
        return ((str[0]+str[1]-'0')&1);
    }
};