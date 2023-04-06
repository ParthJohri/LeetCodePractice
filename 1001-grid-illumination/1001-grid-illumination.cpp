class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        set<pair<int,int>> s;
        map<int,int> row,col,diag,antidiag;
        vector<int> ans;
        for(auto& i:lamps){
            int x=i[0],y=i[1];
            if(!s.count({x,y})){
                row[x]++;
                col[y]++;
                diag[x+y]++;
                antidiag[x-y]++;
                s.insert({x,y});
            } 
        }
        for(auto& i:queries){
            int x=i[0],y=i[1];
            if(row[x]>0 or col[y]>0 or diag[x+y]>0 or antidiag[x-y]>0) {
                ans.push_back(1);
                for(int a=-1;a<=1;a++){
                    for(int b=-1;b<=1;b++){
                        int xx=x+a,yy=y+b;
                        if(xx>=0 and xx<n and yy>=0 and yy<n and s.count({xx,yy})){
                            s.erase({xx,yy});
                            row[xx]--;
                            col[yy]--;
                            diag[xx+yy]--;
                            antidiag[xx-yy]--;
                        }
                    }
                }
            }
            else ans.push_back(0);
        }
        return ans;
    }
};