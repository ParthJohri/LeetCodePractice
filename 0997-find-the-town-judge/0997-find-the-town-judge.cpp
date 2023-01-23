class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> m,p;
        if(n==1) return n;
        for(auto i:trust){
            m[i[1]]++;
            p[i[0]]++;
        }
        for(auto i:m){
            if(i.second==n-1 and !p.count(i.first))
                return i.first;
        }
        return -1;
    }
};