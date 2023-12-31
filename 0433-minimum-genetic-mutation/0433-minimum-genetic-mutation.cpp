class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> s(bank.begin(),bank.end());
        if(s.find(endGene)==s.end()) return -1;
        queue<string>q;
        q.push(startGene);
        int dist=0;
        vector<char> choices={'A','C','G','T'};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string str=q.front();
                q.pop();
                if(str==endGene) return dist;
                s.erase(str);
                string t=str;
                for(int i=0;i<8;i++){
                    t=str;
                    t[i]='A';
                    if(s.count(t)) q.push(t);
                    t[i]='C';
                    if(s.count(t)) q.push(t);
                    t[i]='G';
                    if(s.count(t)) q.push(t);
                    t[i]='T';
                    if(s.count(t)) q.push(t);
                }
            }
            dist++;
        }
        return -1;
    }
};