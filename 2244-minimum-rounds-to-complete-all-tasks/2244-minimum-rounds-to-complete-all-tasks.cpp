class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        int count=0;
        for(auto i:tasks)
            m[i]++;
        for(auto i:m)
        {
            if(i.second<2)
                return -1;
            else if(i.second==2)
                count++;
            else if(i.second==3)
                 count++;
            else if(i.second>3)
                count+=ceil((double)i.second/3);
        }
        return count;
    }
};