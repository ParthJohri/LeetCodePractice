class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> m;
        string str="";
        vector<string> v;
        unordered_map<char,int> n,fn;
        for(auto i:words2){
            for(auto j:i){
                m[j]++;
            }
            for(char j='a';j<='z';j++){
                n[j]=max(n[j],m[j]);
            }
            m.clear();
        }
        for(auto i:n){
            if(i.second>0){
                fn[i.first]=i.second;}
        }
        // for(auto i:fn){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        unordered_map<char,int> temp;
        for(auto i:words1){
            int c=0;
            for(auto j:i){
                temp[j]++;
            }
            for(auto j:fn){
                if(temp[j.first]>=j.second)
                    ++c;
            }
            if(c==fn.size())
                v.push_back(i);
            temp.clear();
        }
        return v;
    }
};