class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(),products.end());
        string temp="";
        int n=products.size(),id=0;
        for(auto i:searchWord){
            temp+=i;
            vector<string>v;
            id=lower_bound(products.begin()+id,products.end(),temp)-products.begin();
            for(int j=id;j<min(id+3,n);j++){
                if(products[j].substr(0,temp.length())==temp){
                    v.push_back(products[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};