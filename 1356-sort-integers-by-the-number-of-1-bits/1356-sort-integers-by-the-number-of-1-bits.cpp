class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> bit(n,vector<int>(2,0));
        vector<int> ans;
            for(int in=0;in<n;in++){
                for(int i=0;i<=31;i++){   
                if(arr[in]&(1<<i)){
                    int temp=bit[in][0];
                    bit[in]={temp+1,arr[in]};
                }
            }
        }
        sort(bit.begin(),bit.end());
        for(auto i:bit){
            ans.push_back(i[1]);
        }
        return ans;
    }
};