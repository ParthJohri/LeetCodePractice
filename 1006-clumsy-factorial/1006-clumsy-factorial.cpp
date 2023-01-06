class Solution {
public:
    int clumsy(int n) {
        int ans=0,i=n;
        if(n<=2) return n;
        bool flag=true;
        for(i=n;i>=3;i--){
            if(flag)
            ans+=((i*(--i))/(--i));
            else
            ans-=(i*(--i))/(--i);
            ans+=--i;
            cout<<ans<<endl;
            flag=false;
        }
        if(i>0 and i<=2) ans-=i;
        return ans;
    }
};