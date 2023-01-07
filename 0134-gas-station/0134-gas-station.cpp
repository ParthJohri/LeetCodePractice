class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0,sum2=0,total=0,start=0;
        for(int i=0;i<gas.size();i++){
            sum+=gas[i];
            sum2+=cost[i];
        }
        if(sum2>sum) return -1;
        for(int i=0;i<gas.size();i++){
           total+=gas[i]-cost[i];
           if(total<0) {start=i+1; total=0;}
        }
        return start;
    }
};