class Solution {
public:
    int m[10]={0};
    bool check(int n){
        while(n!=0){
            m[n%10]++;
            n/=10;
        }
        for(int i=0;i<10;i++){
            if(m[i]!=0 and i!=m[i]) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
       n+=1;
       while(true){
           memset(m,0,sizeof m);
           if(check(n)) break;
           n++;
       }
       return n;
    }
};