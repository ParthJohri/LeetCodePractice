class Solution {
public:
    vector<int> closestDivisors(int num) {
        int n=num+1,nn=num+2;
        vector<int> a,aa,b,bb,ans;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                a.push_back(i);
                aa.push_back(n/i);
            }
        }
        for(int i=1;i*i<=nn;i++){
            if(nn%i==0){
                b.push_back(i);
                bb.push_back(nn/i);
            }
        }
        int va,vb;
        va=abs(a[a.size()-1]-aa[aa.size()-1]);
        vb=abs(b[b.size()-1]-bb[bb.size()-1]);
        if(va<vb){
            ans.push_back(a[a.size()-1]);
            ans.push_back(aa[aa.size()-1]);
        }
        else{
            ans.push_back(b[b.size()-1]);
            ans.push_back(bb[bb.size()-1]);
        }
        return ans;
    }
};