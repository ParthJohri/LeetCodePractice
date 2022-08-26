class Solution {
public:
    vector<int> ans;
    void factors(int n){
        vector<int> start,end;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                start.push_back(i);
                if(n/i!=i)
                  end.push_back(n/i);  
            }
        }
        for(auto i:start) ans.push_back(i);
        reverse(end.begin(),end.end());
        for(auto i:end) ans.push_back(i);
    }
    void print(){
        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int kthFactor(int n, int k) {
        factors(n);
        print();
        if(k>ans.size()) return -1;
        return ans[k-1];
    }
};