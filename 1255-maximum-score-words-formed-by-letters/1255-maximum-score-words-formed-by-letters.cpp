class Solution {
public:
    int ans=0;
    void solve(vector<string>&words,int index,vector<int>&score,int sum,unordered_map<char,int>&map){
        if(index>=words.size()){
            ans=max(ans,sum);
            return;
        }
        string word=words[index];
        unordered_map<char,int> tmap=map;
        int val=0;
        bool canFormWord=true;
        for(auto i:word){
            tmap[i]--;
            if(tmap[i]<0){
                canFormWord=false;
                break;
            }
            val+=score[i-'a'];
        }
        if(canFormWord)
            solve(words,index+1,score,sum+val,tmap);
            solve(words,index+1,score,sum,map);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int> map;
        for(auto i:letters) map[i]++;
        solve(words,0,score,0,map);
        return ans;
    }
};