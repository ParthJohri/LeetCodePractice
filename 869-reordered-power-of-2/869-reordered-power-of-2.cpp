class Solution {
public:
    bool powerof2(string s){
        int n=stoi(s);
        int l=log2(n);
        return (n-(int)pow(2,l))==0;
    }
    bool reorderedPowerOf2(int n) {
        if(n==1) return true;
        string s=to_string(n);
        sort(s.begin(),s.end());
        do{
            if(s[0]!='0' and powerof2(s)==true) return true;
        }while(next_permutation(s.begin(),s.end()));
        return false;
    }
};