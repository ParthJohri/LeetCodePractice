class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> j;
        int count=0;
        for(int i=0;i<stones.length();i++)
        {
            j[stones[i]]++;
        }
        for(auto i: jewels)
        {
            if(j[i]>0)
                count+=j[i];
        }
        return count;
    }
};