class Solution {
public:
    int count=0;
    void merge(vector<int> &nums,int l,int r){
        int i=l,m=(l+r)/2,j=m+1;
        vector<int> temp(r-l+1,0);
        int x=0;
        for(i=l;i<=m;i++){
            while(j<=r&&nums[i]>2*1ll*nums[j]){
                j++;
            }
            count+=j-(m+1);
        }
        i=l;
        j=m+1;
        while(i<=m&&j<=r){
            if(nums[i]<=nums[j]){
                temp[x++]=nums[i++];
            }
            else{
                temp[x++]=nums[j++];
            }
        }
        while(i<=m){
            temp[x++]=nums[i++];
        }
        while(j<=r){
            temp[x++]=nums[j++];
        }
        x=0;
        for(int i=l;i<=r;i++){
            nums[i]=temp[x++];
        }
    }
    void reverse(vector<int> &nums,int l,int r){
        int mid=l+(r-l)/2;
        if(l>=r) return;
        reverse(nums,l,mid);
        reverse(nums,mid+1,r);
        merge(nums,l,r);
    }
    int reversePairs(vector<int>& nums) {
        reverse(nums,0,nums.size()-1);
        return count;
    }
};