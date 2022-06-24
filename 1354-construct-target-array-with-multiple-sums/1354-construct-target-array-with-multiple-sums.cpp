class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>p(target.begin(),target.end());
        long long int sum=0,n=target.size();
        for(auto i:target) sum+=i;
        if(n==1) return target[0]==1;
        while(p.top()!=1)
        {
            int num=p.top();
            p.pop();
            if(sum-num==1) return true;
            sum-=num;
            int x=num%sum;
            if(x==0||x==num) return false;
            p.push(x);
            sum+=x;
        }
        return true;
    }
};