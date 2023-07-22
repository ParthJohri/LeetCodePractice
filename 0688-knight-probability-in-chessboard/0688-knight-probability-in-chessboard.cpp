class Solution {
private:
    int dx[8]={2,2,-2,-2,1,1,-1,-1};
    int dy[8]={1,-1,1,-1,2,-2,2,-2};
    int num;
public:
    bool check(int cx,int cy){
        return cx>=0 and cy>=0 and cx<num and cy<num;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> curr(n+1,vector<double>(n+1,0.0));
        vector<vector<double>> next(n+1,vector<double>(n+1,0.0));
        double ans=0.0;
        this->num=n;
        curr[row][column]=1;
        for(int i=1;i<=k;i++){
            for(int r=0;r<n;r++){
                for(int col=0;col<n;col++){
                    if(curr[r][col]!=0){
                        for(int it=0;it<8;it++){
                        int cx=r+dx[it];
                        int cy=col+dy[it];
                        if(check(cx,cy)) 
                            next[cx][cy]+=((1/8.0)*curr[r][col]);
                        }
                    }
                }
            }
            curr = next;
            next = vector<vector<double>>(n+1,vector<double>(n+1,0.0));
        }
        for(auto i:curr){
            for(auto j:i){
                ans+=j;
            }
        }
        return ans;
    }
};