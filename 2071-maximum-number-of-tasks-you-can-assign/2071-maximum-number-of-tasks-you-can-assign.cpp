class Solution {
public:
    bool check(vector<int>& t, vector<int>& w, int p, int s,int mid){
        multiset<int> m(w.begin(),w.end());
        for(int i=mid-1;i>=0;i--){
            auto it=m.end();
            --it;
            if(*it<t[i]){
                if(p<=0) return false;
                it = m.lower_bound(t[i]-s);
                if(it==m.end()) return false;
                p--;
            }
            m.erase(it);
        }
        return true;
        
    }
    int maxTaskAssign(vector<int>& t, vector<int>& w, int p, int s) {
        sort(t.begin(),t.end());
        sort(w.begin(),w.end());
        int n=min(t.size(),w.size());
        int l=0,r=n,ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(t,w,p,s,mid)){
                l=mid+1;
                ans=mid;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};