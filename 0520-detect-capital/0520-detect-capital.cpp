class Solution {
public:
    bool detectCapitalUse(string word) {
        bool ans=isupper(word[0]);
        if(!ans){
            for(auto i:word){
                if(isupper(i)) return false;
            }
            return true;
        }
        else{
            int x=0,l=word.length();
            for(auto i:word){
                if(islower(i)) ++x;
            }
            return x==l-1 or x==0;
        }
    }
};