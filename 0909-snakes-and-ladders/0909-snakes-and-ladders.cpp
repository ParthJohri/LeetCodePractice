class Solution {
public:
    pair<int,int> getCo(int x,int &n){
        int r=(x-1)/n;
        int rb=(n-1)-r;
        int c=(x-1)%n;
        if(n%2==1 and rb%2==1 or n%2==0 and rb%2==0)
            c=(n-1)-c;
        return {rb,c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<vector<bool>> visit(n,vector<bool>(n,false));
        visit[n-1][0]=true;
        queue<int> q;
        q.push(1);
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){ 
                int fr=q.front();
                q.pop();
                if(fr==n*n) return ans;
                for(int i=1;i<=6;i++){
                    if(fr+i>n*n) break;
                    pair<int,int> co=getCo(fr+i,n);
                    int row=co.first;
                    int col=co.second;
                    if(visit[row][col]==true) continue;
                    visit[row][col]=true;
                    if(board[row][col]==-1) q.push(fr+i);
                    else q.push(board[row][col]);
                }
            }
            ans++;
        }
        return -1;
    }
};