class Solution {
public:
    int numberOfSteps(int num) {
    int count=0;
        while(num!=0)
        {
            if(num&1)
            {
                num=num-1;
                ++count;
                continue;
            }
            num=num/2;
            ++count;
        }
        return count;
    }
};