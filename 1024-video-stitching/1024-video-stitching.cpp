class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int min=0,max=0,count=0;
        while(max<time){
            for(auto i:clips){
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