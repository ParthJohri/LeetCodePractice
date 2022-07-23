class Solution {
public:
    int gcd(int a, int b){
        if(b==0) 
            return a;
        return gcd(b,a%b);
    }
    bool canMeasureWater(int j1, int j2, int t) {
       if(j1+j2<t) return false;
       return t%gcd(j1,j2)==0;
    }
};