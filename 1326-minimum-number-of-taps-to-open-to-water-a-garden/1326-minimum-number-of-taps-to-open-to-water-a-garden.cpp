class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> lr;
        int x=0,min=0,max=0,count=0;
        for(auto i:ranges){
            lr.push_back({x-i,x+i});
            x++;
        }
        while(max<n){
            for(auto i:lr){
                if(min>=i[0] and max<=i[1]){
                    max=i[1];
                }
            }
            if(min==max) return -1;
            min=max;
            count++;
        }
        return count;
    }
};