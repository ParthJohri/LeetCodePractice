class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        sentence+=" ";
        string word="";
        int x=1;
        for(auto i:sentence) {
            word+=i;
            if(i==' '){
                if(word.find(searchWord)==0)
                    return x;
                x++;
                word="";
            }
        }
        return -1;
    }
};