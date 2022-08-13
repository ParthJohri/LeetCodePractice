class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> m(1001,0);
        for(int i:arr){
            m[i]++;
        }
        int x=1;
        while(k && x<1001){
            if(m[x]==0)
                k--;
            m[x++];
        }
        return --x+k;
    }
};