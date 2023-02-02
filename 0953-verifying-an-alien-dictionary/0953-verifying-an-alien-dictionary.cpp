class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> m;
        int x=1;
        for(auto i:order){
            m[i]=x++;
        }
        for(int i=0;i<words.size()-1;i++){
            x=0;
            while(words[i][x]==words[i+1][x] and x<min(words[i].length(),words[i+1].length())){
                x++;
            }
            if(m[words[i][x]]>m[words[i+1][x]]) return false;
        }
        return true;
    }
};