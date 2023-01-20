class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<int>>&visit, int i, int j,int& color,int&pc){
        visit[i][j]=1;
        image[i][j]=color;
        int x[4]={1,0,-1,0};
        int y[4]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int xx=x[k]+i;
            int yy=y[k]+j;
            if(xx<0 or yy<0 or xx>=image.size() or yy>=image[0].size()) continue;
            if(visit[xx][yy]!=1 and image[xx][yy]==pc){
            dfs(image,visit,xx,yy,color,pc);
            }
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visit(image.size(),vector<int>(image[0].size(),0));
        int pc=image[sr][sc];
        dfs(image,visit,sr,sc,color,pc);
        return image;
    }
};