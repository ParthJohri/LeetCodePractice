class Solution {
public:
    vector<int> grayCode(int n) {
        int pn=(int)pow(2,n);
        vector<int> v(pn,0);
        for(int i=0;i<pn;i++){
            v[i]=i^(i>>1);
        }
        return v;
    }
};