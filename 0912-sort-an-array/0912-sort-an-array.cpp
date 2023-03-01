class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
    void merge(vector<int>&nums,int start, int mid, int end){
        int lh=mid-start+1,rh=end-mid,i=0,j=0,x=start;
        int lhs[lh],rhs[rh];
        for(i=0;i<lh;i++){
            lhs[i]=nums[start+i];
        }
        for(j=0;j<rh;j++){
            rhs[j]=nums[mid+j+1];
        }
        i=0,j=0;
        while(i<lh and j<rh){
            if(lhs[i]<rhs[j]){
                nums[x++]=lhs[i++];
            }
            else 
                nums[x++]=rhs[j++];
        }
        while(i<lh){
            nums[x++]=lhs[i++];
        }
        while(j<rh){
            nums[x++]=rhs[j++];
        }
    }
    void mergesort(vector<int>&nums,int s, int e){
        if(s>=e){
            return;
        }
        int m=(s+e)/2;
        mergesort(nums,s,m);
        mergesort(nums,m+1,e);
        merge(nums,s,m,e);
    }
};