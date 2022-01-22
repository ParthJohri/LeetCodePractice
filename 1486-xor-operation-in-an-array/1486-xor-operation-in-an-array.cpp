class Solution {
public:
    int xorOperation(int n, int start) {
        int sum=0;
        vector<int> v(n);
        for(int i=0;i<n;i++)
           { v[i]=start+2*i;
            sum=sum^v[i];}
        return sum;
    }
};