class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> m;
        int mxfruits=0,l=0;
        for(int i=0;i<fruits.size();i++){
            m[fruits[i]]++;
            if(m.size()>2){
                m[fruits[l]]--;
                if(m[fruits[l]]==0)
                m.erase(fruits[l]);
                l++;
            }
            else
            mxfruits=max(mxfruits,i-l+1);
        }
        return mxfruits;
    }
};