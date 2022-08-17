class ProductOfNumbers {
public:
    vector<int> s,pr;
    int pos=-1;
    ProductOfNumbers() {
        vector<int> temp;
        s=temp;
    }
    
    void add(int num) {
        s.push_back(num);
        if(num==0) pos=s.size();
        if(pr.empty() or pr.back()==0) pr.push_back(s.back());
        else 
        pr.push_back(s.back()*pr.back());
        // print(pr);
    }
    void print(vector<int>&pr){
        for(auto i:pr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int getProduct(int k) {
        if(k>s.size()) return 0;
        if(pos!=-1 and s.size()-pos<k){
            return 0;
        }
        if(k==s.size()) return pr[s.size()-1];
        int dv=pr[s.size()-k-1];
        if(dv==0) dv=1;
        if(pr[s.size()-k]==0) return 0;
        return pr[s.size()-1]/dv;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */