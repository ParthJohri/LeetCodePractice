class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        string s1,s2,s3;
        for(auto i:firstWord)
            s1+=i-'1';
        for(auto i:secondWord)
            s2+=i-'1';
        for(auto i:targetWord)
            s3+=i-'1';
        int n1=stoi(s1);
        int n2=stoi(s2);
        int n3=stoi(s3);
        return (stoi(s1)+stoi(s2)==stoi(s3));
    }
};