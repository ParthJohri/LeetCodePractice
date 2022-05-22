class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> v,kn;
        while(k!=0)
            {
                kn.push_back(k%10);
                k/=10;
            }
        reverse(kn.begin(),kn.end());
        int v1=num.size()-1;
        int v2=kn.size()-1;
        int sum=0,car=0;
        int mx=max(v1,v2);
        while(mx>=0)
        {
            if(v1>=0)
                sum+=num[v1--];
            if(v2>=0)
                sum+=kn[v2--];
            sum+=car;
            car=sum/10;
            sum=sum%10;
            cout<<sum<<" ";
            v.push_back(sum);
            sum=0;
            mx--;
        }
        cout<<car<<endl;
        if(car!=0)
        v.push_back(car);
        reverse(v.begin(),v.end());
        return v;
    }
};