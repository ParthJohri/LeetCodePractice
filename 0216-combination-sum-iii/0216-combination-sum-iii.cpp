class Solution {
public:
    vector<vector<int>> ans;
    void print(vector<int>&temp){
        for(auto i:temp) cout<<i<<" ";
        cout<<endl;
    }
    void recur(int k,int n,vector<int>temp,int num){
        if(k<0 or n<0 or num>10) return;
        // print(temp);
        if(k==0 and n==0){
            ans.push_back(temp);
            return;
        }
        recur(k,n,temp,num+1);
        if(n-num>=0){
            temp.push_back(num);
            recur(k-1,n-num,temp,num+1);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        for(int i=1;i<=9;i++){
            if(n-i>=0){
                temp.push_back(i);
                recur(k-1,n-i,temp,i+1);
                temp.pop_back();
            }
        }
        return ans;
    }
};