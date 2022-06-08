class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int ml=arr.size()/2;
        unordered_map<int,int> m;
        priority_queue<int>p;
        for(auto i:arr) m[i]++;
        for(auto i:m)
        {
            p.push(i.second);
        }
        int count=0,c=0;
        while(!p.empty())
        {
            c+=p.top();
            count++;
            if(c>=ml)
                return count;
            p.pop();
        }
        return count;
    }
};