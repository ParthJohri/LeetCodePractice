class Solution {
public:
    long long int g=0;
    void merge(int l,int r,vector<int> &arr) {
        int mid=l+(r-l)/2;
        int left_size=mid-l+1,right_size=r-mid;
        int left[left_size],right[right_size];
        for(int i=0;i<left_size;i++)
        {
            left[i]=arr[l+i];
        }
        for(int i=0;i<right_size;i++)
        {
            right[i]=arr[mid+1+i];
        }
        int i=0,j=0,merge=l;
        while(i<left_size && j<right_size)
        {
            if(left[i]<=right[j])
            {
                arr[merge]=left[i];
                i++;
            }
            else
            {
                arr[merge]=right[j];
                g+=left_size-i;
                j++;
            }
            merge++;
        }
        while(i<left_size)
        {
            arr[merge++]=left[i++];
        }
        while(j<right_size)
        {
            arr[merge++]=right[j++];
        }
    }
    void mergesort(int l,int r,vector<int> &arr) {
        int mid=l+(r-l)/2;
        if(l>=r) return;
        mergesort(l,mid,arr);
        mergesort(mid+1,r,arr);
        merge(l,r,arr);
    }
    bool isIdealPermutation(vector<int>& nums) {
        int l=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1]) l++;
        }
        mergesort(0,nums.size()-1,nums);
        return l==g;
    }
};