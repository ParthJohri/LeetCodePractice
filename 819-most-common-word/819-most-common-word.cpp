class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // Map to store the frequency of the words
        unordered_map<string,int> m;
        // To store the temp word and 
        // the most frequenct used word after banned word
        string temp="",word="";
        // To store all the words
        vector<string> token;
        // Adding a space to extract last word of the paragraph
        paragraph+=" ";
        // Extracting words from the paragraphs
        for(auto i:paragraph)
        {
            if(isalpha(i))
                temp+=tolower(i);
            else if(i=='!'||i=='?'||i==','||i==';'||i=='.'||i==' ')
                {token.push_back(temp);
                 temp="";
            continue;}
        }
        // Counting the frequency of each word 
        // in the paragraph
        for(auto i: token)
        {
            m[i]++;
        }
        // Removing the word which are banned 
        // from the paragraph
        for(auto i:banned)
        {
            m[i]=0;
        }
        // To store the maximum frequency of the word
        int mx=0;
        for(auto i:m)
        {
            // There will be null values in the string 
            // because of multiple delimiters
            if(i.second>mx&&i.first!="")
                {mx=i.second;
                 word=i.first;}
        }
        // Returning the most frequent word afterbanned
        return word;
    }
};