class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> m;
        int count = 0;
        for(auto i:time){
            int v=i%60;
            if(v==0)
            count+=m[v];
            else
            count+=m[60-v];
            m[v]++;
        }
        return count;
    }
};