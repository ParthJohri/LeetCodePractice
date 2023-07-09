class Solution {
public:
    int largestVariance(string s) {
        int ans=0;
        for(char i='a';i<='z';i++){
            for(char j='a';j<='z';j++){
                if(i==j) continue;
                for(int rev=1;rev<=2;rev++){
                    int minCount=0,maxCount=0;
                    for(auto ch:s){
                        if(i==ch) maxCount++;
                        if(j==ch) minCount++;
                        if(maxCount>0 and minCount>0){
                          ans=max(ans,maxCount-minCount);  
                        }
                        if(minCount>maxCount){
                            maxCount=minCount=0;
                        }
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};