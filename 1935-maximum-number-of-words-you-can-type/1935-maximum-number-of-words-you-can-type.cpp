class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int> c;
        for(auto i: brokenLetters)
            c[i]++;
        text+=" ";
        int count=0,word=0,defaulty=0;
        for(auto i:text)
        {
            if(i!=' ')
            {
                if(c[i]>0)
                   { 
                    ++count;
                       }
            }
           
            else
                 {++word;
                  if(count>=1)
                    ++defaulty;
                 count=0;}
        }
        return (word-defaulty>0?word-defaulty:0);
    }
};