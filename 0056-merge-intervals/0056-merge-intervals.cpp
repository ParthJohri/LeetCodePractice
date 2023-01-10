class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])
        return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& i) {
        sort(i.begin(),i.end(),cmp);
        vector<vector<int>> ans;
        i.push_back({INT_MAX,INT_MAX});
        int n=i.size(),ini,ene;
        for(int v=0;v<n-1;v++){
            ini=i[v][0];
            ene=i[v][1];
            if(i[v][1]>=i[v+1][0]){
                while(v<n-1 and ene>=i[v+1][0]){
                    ene=max(ene,i[v+1][1]);
                    v++;
                }
                ans.push_back({ini,ene});
            }
            else{
                ans.push_back({ini,ene});
            }
        }
        return ans;
    }
};