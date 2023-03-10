class Solution {
public:
    int sum=0,size;
    vector<int> pr;
    Solution(vector<int>& w) {
        size=w.size();
        pr=w;
        for(int i=1;i<w.size();i++){
            pr[i]=pr[i-1]+w[i];
        }
        sum=pr.back();
    }
    
    int pickIndex() {
        int val=rand()%sum;
        int ans=upper_bound(pr.begin(),pr.end(),val)-pr.begin();
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */