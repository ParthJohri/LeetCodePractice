class Solution {
public:
    // To check if the string is 0 00 000 0000 00000 000000 0000000 ...
    // All are 0
    int ascii(string &s)
    {
        int val=0;
        for(auto i:s)
        {
            val+=i-'0';
        }
        return val;
    }
    // Removing Initial Zeroes 
    string rmzeros( string &str)
    {
        string nstr="";
        // Only for string of number 0
        if(str=="0"||ascii(str)==0)
            return "0";
        // for Normal string of nummber N
        else if(str[0]!='0')
            return str;
        else
        // Removing the Zeroes by using substring method
        {int pos=0;
            for(int i=0;i<str.length();i++)
            {
                if(str[i]!='0')
                {pos=i;
                 break;}
            }
                nstr=str.substr(pos,str.length()); // Removing the Initial Zeroes
        }
        return nstr;
    }
    int numDifferentIntegers(string word) {
        // Replacing all the characters with space
        for(int i=0;i<word.length();i++)
        {
            if(isalpha(word[i]))
                word[i]=' ';
        }
        word+=' ';
        // Creating unordered set for O(1) Average Case and O(N) Worst Case
        unordered_set<string> s;
        string temp="";
        
        for(auto i: word)
        {
            // Extracting the words of the string
            if(i!=' ')
                temp+=i;
            else
                {
                if(temp!="")
                s.insert(rmzeros(temp));// Removing initial zeroes of the string
                temp="";}
        }
        // Reutrning the number of Unique Elments in a Set
        return s.size();
    }
};