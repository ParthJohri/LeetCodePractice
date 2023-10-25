class Solution {
public:
    int sum(int n){
        int sum=0;
        while(n){
            sum+=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n,fast=sum(n);
        while(slow!=fast){
            slow=sum(slow);
            fast=sum(sum(fast));
        }
        cout<<slow<<endl;
        cout<<fast<<endl;
        return slow==1;
    }
};