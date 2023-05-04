class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;
        int n=senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='R') r.push(i);
            else d.push(i);
        }
        while(!r.empty() and !d.empty()){
            int a=r.front(),b=d.front();
            r.pop();
            d.pop();
            if(a<b) r.push(a+n);
            else d.push(b+n);
        }
        if(r.size()>d.size()) return "Radiant";
        else return "Dire";
    }
};