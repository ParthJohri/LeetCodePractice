class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s;
        bitset<200001> b; // Uses less space, can also be used to convert decimal to binary
        for(auto i:candyType) s.insert(i), b.set(i+100000);
        return min(b.count(),candyType.size()/2);
        // return min(s.size(),candyType.size()/2);
    }
};