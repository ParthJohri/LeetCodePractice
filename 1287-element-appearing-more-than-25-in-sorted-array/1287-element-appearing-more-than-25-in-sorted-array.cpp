class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        // Binary Search TC:O(logN) SC: O(1)
        int n=arr.size();
        vector<int> v={arr[n/4],arr[n/2],arr[3*n/4]};
        for(auto i:v) {
            int l=lower_bound(arr.begin(),arr.end(),i)-arr.begin();
            int h=upper_bound(arr.begin(),arr.end(),i)-arr.begin();
            if(h-l>n/4) return i;
        }
        return arr[0];
        // Linear Search TC: O(N) SC:O(1)
        int c=arr.size()/4,ans=0;
        if(arr.size()==1) return arr[0];
        for(int i=0;i<arr.size()-1;i++) {
            if(arr[i]==arr[i+1]) {
                int c2=c;
                for(;i<arr.size()-1;i++) {
                    if(arr[i]==arr[i+1])
                        c2--;
                    else 
                        break;
                }
                 c2--;
                 if(c2<0)
                 return arr[i];
                 else if(c2==0)
                 ans=arr[i];
            }
        }
        return ans;
    }
};