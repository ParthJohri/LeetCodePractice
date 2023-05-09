class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n=matrix.size(), m=matrix[0].size(),ii=0,jj=0;
        if(n==1 and m==1)
            ans.push_back(matrix[0][0]);
        else if(n==1 or m==1){
            if(m==1)
              for(int i=0;i<n;i++){
            ans.push_back(matrix[i][0]);
        }
            if(n==1)
              for(int i=0;i<m;i++){
            ans.push_back(matrix[0][i]);
        }
        }
        set<pair<int,int>> s;
        while(n!=1 and m!=1){
        for(int i=jj;i<m;i++){
            if(s.find({ii,i})==s.end())
            ans.push_back(matrix[ii][i]);
            s.insert({ii,i});
        }
         for(int i=ii+1;i<n;i++){
            if(s.find({i,m-1})==s.end())
            ans.push_back(matrix[i][m-1]);
             s.insert({i,m-1});
        }
          for(int i=m-2;i>=jj+1;i--){
            if(s.find({n-1,i})==s.end())
            ans.push_back(matrix[n-1][i]);
              s.insert({n-1,i});
        }
          for(int i=n-1;i>=ii+1;i--){
              if(s.find({i,jj})==s.end())
            ans.push_back(matrix[i][jj]);
              s.insert({i,jj});
        }
    n--;
    m--;
    ii++;
    jj++;
    }
    return ans;
        }
};