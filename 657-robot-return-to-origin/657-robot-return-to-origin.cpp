class Solution {
public:
    bool judgeCircle(string moves) {
        int sx=0,sy=0;
        for(auto i: moves)
        {
            if(i=='L')
                sx-=1;
            else if(i=='R')
                sx+=1;
            if(i=='U')
                sy+=1;
            else if(i=='D')
                sy-=1;
        }
        return (sx==0&&sy==0);
    }
};