class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int right=0,left=0,ans=0,n=s.length();
        map<char,int> m;
        while(right<n){
            m[s[right]]++;
            if(m[s[right]]>1){
                while(s[left]!=s[right]){
                    m[s[left]]--;
                    left++;
                }
                m[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);   
            right++;
        }
        return ans;
    }
};