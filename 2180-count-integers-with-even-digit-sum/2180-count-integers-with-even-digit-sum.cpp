class Solution {
public:
    int sum(int num){
        int sum=0;
        while(num!=0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int countEven(int num) {
        // int count=0;
        // for(int i=1;i<=num;i++){
        //     if(sum(i)%2==0)
        //         count++;
        // }
        // return count;
        int s=sum(num);
        return s%2==0?num/2:(num-1)/2;
    }
};