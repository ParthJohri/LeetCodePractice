class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int frequencyAlphabet[26],maxFrequency=0,n=s.length(),left=0,right=0,ans=0;
        memset(frequencyAlphabet,0,sizeof frequencyAlphabet);
        for(right=0;right<n;right++){
            maxFrequency=max(maxFrequency,++frequencyAlphabet[s[right]-'A']);
            int windowSize=right-left+1;
            if(windowSize-maxFrequency>k){
                --frequencyAlphabet[s[left++]-'A'];
            }
        }
        ans=right-left;
        return ans;
    }
};