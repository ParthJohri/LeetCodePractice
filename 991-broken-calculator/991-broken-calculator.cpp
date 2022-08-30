class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count=0;
        while(target!=startValue){
            if(target>startValue and target%2==0)
                target/=2;
            else
                target++;
            count++;
        }
        return count;
    }
};