class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(auto i:words) {
            if(i.find(pref)==0)
                count++;
        }
        return count;
    }
};