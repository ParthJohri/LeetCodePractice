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
        return (stoi(s1)+stoi(s2)==stoi(s3));
    }
};