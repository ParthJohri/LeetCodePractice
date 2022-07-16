class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        for(int i=0;i<(int)pow(2,n);i++){
            v.push_back(i^(i>>1));
        }
        return v;
    }
};