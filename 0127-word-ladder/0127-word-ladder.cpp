class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<string> q;
        int dist=0;
        q.push(beginWord);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string str=q.front();
                q.pop();
                s.erase(str);
                if(str==endWord) return dist+1;
                string t="";
                for(int i=0;i<str.size();i++){
                    t=str;
                    for(char ch='a';ch<='z';ch++){
                        t[i]=ch;
                        if(s.count(t)) q.push(t);
                        
                    }
                }
            }
            dist++;
        }
        return 0;
    }
};