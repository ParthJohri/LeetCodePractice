class Solution {
public:
    int partitionString(string s) {
        int count=1;
        map<char,int> m;
        for(auto i:s){
            if(m.count(i)){
                m.clear();
                count++;
            }
            m[i]++;
        }
        return count;
    }
};