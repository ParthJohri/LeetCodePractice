class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> shash(26,0);
        vector<int> phash(26,0);
        vector<int> ans;
        if(p.length()>s.length()||s=="")
            return ans;
        for(int i=0;i<p.length();i++)
            shash[s[i]-'a']++;
        for(auto i: p)
            phash[i-'a']++;
        
        int left=0,n=p.length(),right=n-1;
        
        while(right<s.length())
        {
            if(phash==shash)
                ans.push_back(left);
            right++;
            if(right!=s.length())
                shash[s[right]-'a']++;
            shash[s[left]-'a']--;
            left++;
        }
        return ans;
    }
};