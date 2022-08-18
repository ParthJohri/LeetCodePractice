class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> m(100001,0);
        for(auto i:arr){
            m[i]++;
        }
        sort(m.begin(),m.end(),greater<int>());
        int n=arr.size(),x=1,t=n;
        for(auto i:m){
            
            int t=t-i;
            cout<<t<<endl;
            if(t<=n/2){
                return x;
            }
            x++;
        }
        return 0;
    }
};