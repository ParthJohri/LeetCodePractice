class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> v(encoded.size()+1,0);
        v[0]=first;
        for(int i=0;i<encoded.size();i++)
            v[i+1]=v[i]^encoded[i];
        return v;
    }
};