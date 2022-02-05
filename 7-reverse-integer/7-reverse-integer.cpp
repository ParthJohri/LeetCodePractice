class Solution {
public:
    int reverse(int x) {
        string s=to_string(x);
        if(s[0]=='-')
        std::reverse(s.begin()+1,s.end());
        else
        std::reverse(s.begin(),s.end());
        long long int num=stoll(s);
        if(num>=INT_MIN&&num<=INT_MAX)
            {return num;}
        else
            return 0;
    }
};