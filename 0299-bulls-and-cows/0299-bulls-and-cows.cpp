class Solution {
public:
    string getHint(string secret, string guess) {
        map<int,int> m,n;
        int x=0,y=0;
        for(auto i:secret){
            m[i-'0']++;
        }
        for(auto i:guess){
            n[i-'0']++;
        }
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
               x++;
               m[secret[i]-'0']--;
               n[guess[i]-'0']--;
            }
        }
        for(auto i:n){
            if(i.second>0 and m[i.first]>0)
            y+=min(i.second,m[i.first]);
        }
        string ans=to_string(x)+"A"+to_string(y)+"B";
        return ans;
    }
};