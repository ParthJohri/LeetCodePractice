class Solution {
public:
    bool isRobotBounded(string instructions) {
        int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int count=0,x=0,y=0;
        for(auto i:instructions){
            if(i=='G') {
                x+=d[count][0];
                y+=d[count][1];
            }
            else if(i=='L') {
                count+=3;
                count%=4;
            }
            else if(i=='R'){
                count+=1;
                count%=4;
            }
        }
        return x==0 and y==0 or count>0;
    }
};