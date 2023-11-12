class Solution {
public:
    int mx=50001;
    int t[5000001]={0};
    
    int sum(int id){
        int s=0;
        while(id>0){
            s+=t[id];
            id-=(id&-id);
        }
        return s;
    }
    void up(int id,int v){
        while(id<=mx){
            t[id]+=v;
            id+=(id&-id);
        }
    }
    int numTimesAllBlue(vector<int>& flips) {
        int count=0,x=1;
        for(auto i:flips){
            up(i,1);
            if(sum(x)==x) ++count;
            x++;
        }
        return count;
    }
};