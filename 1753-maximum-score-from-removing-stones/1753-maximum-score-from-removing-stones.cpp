class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> p;
        int count=0;
        p.push(a);
        p.push(b);
        p.push(c);
        while(true){
            vector<int> v;
            while(!p.empty()){
                if(p.top()!=0)
                v.push_back(p.top());
                p.pop();
            }
            if(v.size()<=1) break;
            v[0]--;
            v[v.size()-1]--;
            for(auto i:v){
                p.push(i);
            }
            count++;
        }
        return count;
    }
};