class Solution {
public:
    bool check[16];
    int ans=0;
    void recur(vector<int>& v,int n,int index){
        if(index>n){
            ++ans;  
            return;
        }
        for(int i=1;i<=n;i++){
            if(!check[i] and (i%index==0 or index%i==0)){
                v.push_back(i);
                check[i]=true;
                recur(v,n,index+1);
                v.pop_back();
                check[i]=false;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> v;
        recur(v,n,1);
        return ans;
    }
};