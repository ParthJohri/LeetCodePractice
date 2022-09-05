class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> m={
            {5,0},
            {10,0},
            {20,0}
        };
        for(auto i:bills){
            m[i]++;
            if(i==5)
                continue;
            else if(i==10){
                if(m[5]<=0)
                    return false;
                else
                    m[5]--;
            }
            else if(i==20){
                if(m[10]>0 and m[5]>0){
                    m[10]--;
                    m[5]--;
                }
                else if(m[5]>=3){
                    m[5]-=3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};