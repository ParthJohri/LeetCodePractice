class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> m={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for(auto i: words)
        {string str="";
            for(auto j:i)
            {
                str+=m[j-'a'];
            }
         s.insert(str);
        }
        return s.size();
    }
};