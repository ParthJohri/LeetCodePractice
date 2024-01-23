class Solution {
public:
    map<int,map<string,int>> m;
    bool func(string& s){
        int m[26]={0};
        for(auto i:s){
            if(m[i-'a']>=1) return false;
            m[i-'a']++;
        }
        return true;
    }
    int recur(vector<string>&arr,int index,string s){
        if(index>=arr.size()){
            if(func(s)){
                return s.size();
            }
            return 0;
        }
        if(!func(s)) return m[index][s]=0;
        // if(m[index].count(s)) return m[index][s];
        int a=0,b=0;
        a=recur(arr,index+1,s+arr[index]);
        b=recur(arr,index+1,s);
        return m[index][s]=max(a,b);
    }
    int maxLength(vector<string>& arr) {
        int ans=0;
        ans=recur(arr,0,"");
        return ans;
    }
};