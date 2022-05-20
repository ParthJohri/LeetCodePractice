class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> v;
        for(auto i:tasks)
            v[i]++;
        int count=0;
        for(auto i:v)
        {
            double c=i.second;
            if(c==1)
                return -1;
            else
                count+=ceil(c/3);
        }
        return count;
    }
};