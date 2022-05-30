class Solution {
public:
    bool checkPowersOfThree(int n) {
        int p=0,temp=INT_MIN;
        while(n>0)
        {              
            p=log10(n)/log10(3);
            cout<<log(abs(n))/log(3)<<" "<<p<<"\n";
            if(temp==p)
                return false;
            n-=(int)pow(3,p);
            temp=p;
        }
        return true;
    }
};