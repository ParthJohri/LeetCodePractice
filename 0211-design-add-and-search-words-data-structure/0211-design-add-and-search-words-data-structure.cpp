class WordDictionary {
public:
    unordered_map<int,vector<string>> m;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        m[word.length()].push_back(word);
    }
    
    bool equals(string &s, string &t){
        int i=0,j=0,m=s.length(),n=t.length();
        while(i<m and j<n){
            if(s[i]==t[j] or s[i]=='.'){
                i++;
                j++;
            }
            else return false;
        }
        return true;
    }
    
    bool search(string word) {
        for(auto&& i:m[word.length()]){
            if(equals(word,i)){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */