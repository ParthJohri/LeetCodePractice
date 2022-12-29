class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans=INT_MIN;
        for(auto i:strs){
            bool f=false;
            int l=i.length();
            for(auto j:i){
                if(isalpha(j)){
                    f=true;
                    break;
                }
            }
            if(!f) ans=max(ans,stoi(i));
            else ans=max(ans,l);
        }
        return ans;
    }
};