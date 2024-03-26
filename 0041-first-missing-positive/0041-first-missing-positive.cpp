class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int arr[100007];
        memset(arr,0,sizeof(arr));
        for(auto i:nums){
            if(i>0 and i<=100007)
            arr[i]++;
        }
        for(int i=1;i<=100005;i++){
            if(arr[i]==0) return i;
        }
        return 0;
    }
};