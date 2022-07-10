class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
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