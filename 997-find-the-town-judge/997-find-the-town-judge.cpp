class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> arr[n+1];
        unordered_map<int,int> m;
        for(auto i:trust){
            arr[i[0]].push_back(i[1]);
        }
        for(int i=1;i<=n;i++){
            for(auto j:arr[i]){
                m[j]++;
            }
        }
        for(auto i:m){
            if(i.second==n-1){
                if(arr[i.first].size()==0)
                    return i.first;
            }
        }
        return n==1?1:-1;
    }
};