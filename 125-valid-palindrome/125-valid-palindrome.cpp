class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(auto i:s)
        {
            if(isupper(i))
            {str+=tolower(i);continue;}
            if(!(isspace(i)||ispunct(i)))
                str+=i;
        }
        string rev=str;
        reverse(str.begin(),str.end());
        cout<<rev<<" "<<str<<endl;
        return rev==str;
    }
};