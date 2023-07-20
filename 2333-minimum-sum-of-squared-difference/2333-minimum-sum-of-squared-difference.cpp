class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        map<long long ,int> m;
        for(int i=0;i<nums1.size();i++){
            m[abs(nums1[i]-nums2[i])]++;
        }
        long long ans=0,total_operations=k1+k2;
        for(int i=1e5;i>=1;i--){
            if(m.count(i)){
                if(total_operations>=m[i]){
                    m[i-1]+=m[i];
                    // deho tum 5 ko reduce karoge toh 4 aayega na toh frequency of 4 will be 
                    // m[4]+=m[5]
                    // chamka ya nhi!
                    total_operations-=m[i];
                    m.erase(i);
                }
                else{
                    m[i]-=total_operations;
                    m[i-1]+=total_operations;
                    break;
                    // why break arey bhai, smjh
                    // total_operations zero ho gye na toh ab reduce kya karega
                }
            }
        }
        for(auto [value,freq]:m){
            ans+=value*1ll*value*1ll*freq;
        }
        return ans;
    }
};