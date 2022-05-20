class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> v;
        for(auto i:tasks)
            v[i]++;
        int count=0;
        for(auto i:v)
        {
// Make sure you use double data type here
            double c=i.second;
            if(c==1)
                return -1;
            else
                count+=ceil(c/3);
//                 Better to use ceil function
//                 {
//                 if(c%3==0)
//                     count+=c/3;
//                 else
//                     count+=c/3+1;
//                }
        }
        return count;
    }
};