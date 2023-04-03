class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==k and n==1) return 0;
        int len=pow(2,n-1),mid=len/2;
        if(k<=mid) return kthGrammar(n-1,k);
        else return !kthGrammar(n-1,k-mid);
    }
};