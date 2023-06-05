class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        double temp;
        temp=c[1][0]-c[0][0]==0?INT_MAX:(c[1][1]-c[0][1])/(1.0*(c[1][0]-c[0][0]));
        for(int i=1;i<c.size()-1;i++){
            auto one=c[i],two=c[i+1];
            if(two[0]-one[0]==0){
                if(temp!=INT_MAX) return false;
                else continue;
            } 
            else if((two[1]-one[1])/(1.0*(two[0]-one[0]))!=temp)
                return false;
        }
        return true;
    }
};