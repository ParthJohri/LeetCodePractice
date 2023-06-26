class Solution {
public:
    int seen=0;
    int ans=0;
    void recur(vector<int>& v,int n,int index){
        if(index>n){
            ++ans;  
            return;
        }
        for(int i=1;i<=n;i++){
            int bit=(1<<i);
            if(!(seen&bit)and (i%index==0 or index%i==0)){
                seen^=(1<<i);
                recur(v,n,index+1);
                seen^=(1<<i);
            }
        }
    }
    int countArrangement(int n) {
        vector<int> v;
        recur(v,n,1);
        for(auto i:v)cout<<i<<" ";
        cout<<endl;
        return ans;
    }
};