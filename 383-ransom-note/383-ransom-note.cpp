class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mag[26]={0};
        for(auto i: magazine)
        {
            mag[i-'a']++;
        }
        for(auto i: ransomNote)
        {
            if(mag[i-'a']--<=0)
                return false;
        }
        return true;
    }
};