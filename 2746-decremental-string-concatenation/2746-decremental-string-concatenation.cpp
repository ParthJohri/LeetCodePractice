class Solution {
public:
   // string word(string&w,string&st){
   //      string ans="";
   //      if(w[w.length()-1]==st[0]){
   //          for(int i=0;i<w.length()-1;i++){
   //              ans+=w[i];
   //          }
   //          ans+=st;
   //      }
   //      else {
   //          ans+=w;
   //          ans+=st;
   //      }
   //      return ans;
   //  }
    int dp[1501][27][27];
    int recur(vector<string>&words,int index,int start,int end){
        if(index>=words.size()) return 0;
        if(dp[index][start-'a'][end-'a']!=-1) return dp[index][start-'a'][end-'a'];
        int mn=INT_MIN,n=words[index].length(),lastChar=words[index][n-1];
        if(words[index][n-1]==start){
            mn=max(mn,1+recur(words,index+1,words[index][0],end));
        }
        else{
            mn=max(mn,0+recur(words,index+1,words[index][0],end));
        }
        if(words[index][0]==end){
            mn=max(mn,1+recur(words,index+1,start,lastChar));
        }
        else{
            mn=max(mn,0+recur(words,index+1,start,lastChar));
        }
        return dp[index][start-'a'][end-'a']=mn;
    }
    int minimizeConcatenatedLength(vector<string>& words) {
        int n=words.size();
        memset(dp,-1,sizeof dp);
        if(words.size()==1) return words[0].length();

        int count=0;
        for(auto i:words){
            count+=i.size();
        }
        int ans=recur(words,1,words[0][0],words[0][words[0].length()-1]);
        return count-ans;
    }
};