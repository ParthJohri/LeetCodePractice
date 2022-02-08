class Solution {
public:
    int sumdigit(int &num)
    {
        int s=0;
        while(num!=0)
        {
            s+=num%10;
            num=num/10;
        }
        return s;
    }
    int addDigits(int num) {
        while(num>9)
        {
            num=sumdigit(num);
        }
        return num;
    }
};