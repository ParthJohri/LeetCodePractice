class Solution {
public:
    int minOperations(int n) {
        if(n==1) return 1;
        bitset<64> a(n);
        if(a.count()==1 or n==1) return 1;
        int ans=0;
        for(int i=0;i<=31;i++){
            int num=n+(1<<i);
            bitset<64> c(num),b(n);
            if(c.count()<b.count()){
                n = num;
                ans++;
            }
        }
        cout<<n<<endl;
        bitset<64> c(n);
        return ans+c.count();
    }
};