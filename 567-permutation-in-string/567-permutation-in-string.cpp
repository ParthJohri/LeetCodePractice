class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> n,t;
        if(s1.length()>s2.length()) return false;
        for(auto i='a';i<='z';i++){
            n[i]=t[i]=0;
        }
        for(int i=0;i<s1.length();i++){
            n[s1[i]]++;
        }
        for(int i=0;i<s1.length();i++){
            t[s2[i]]++;
            cout<<s2[i]<<" ";
        }
        cout<<endl;
        if(t==n) return true;
        for(int i=s1.length();i<s2.length();i++){
            t[s2[i-s1.length()]]--;
            t[s2[i]]++;
            if(t==n) return true;
            cout<<s2[i]<<" ";
        }
        cout<<endl;
        return false;
    }
};