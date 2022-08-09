class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        long long int ans=1e9+7,count=0;

        unordered_map< long long int,long long int> m;
        for(auto i:arr) m[i]++;
        for(int i=1;i<arr.size();i++){
            for(int j=i-1;j>=0;j--){
                if(arr[i]%arr[j]==0 && m[arr[i]/arr[j]])
                    m[arr[i]]+=(m[arr[j]]%ans*m[arr[i]/arr[j]]%ans)%ans;
            }
        }
        for(auto i:m){
            count+=i.second%ans;
        }
        return count%ans;
    }
};