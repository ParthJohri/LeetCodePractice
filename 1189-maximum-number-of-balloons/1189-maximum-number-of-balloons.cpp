class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m={
            {'b',0},
            {'a',0},
            {'l',0},
            {'o',0},
            {'n',0}
        };
        unordered_map<char,int> n={
            {'b',1},
            {'a',1},
            {'l',2},
            {'o',2},
            {'n',1}
        };
        int mn=INT_MAX;
        for(auto i:text){
            if(m.count(i)){
                m[i]++;
            }
        }
        for(auto i:m){
            mn=min(mn,i.second/n[i.first]);
        }
        return mn;
    }
};