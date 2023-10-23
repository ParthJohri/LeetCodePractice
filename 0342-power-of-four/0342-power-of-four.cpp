class Solution {
public:
    bool isPowerOfFour(int n) {
        int count = 0;
        bool flag = true;
        for(int i=31;i>=0;i--){
            if((n&(1<<i))){
                count++;
                if(i%2) flag = false;
            }
        }
        cout<<count<<endl;
        return flag and count==1;
    }
};