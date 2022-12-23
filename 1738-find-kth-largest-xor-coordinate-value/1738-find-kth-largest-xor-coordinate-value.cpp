class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int> p;
        vector<vector<int>> a,b;
        for(auto i:matrix){
            vector<int> t;
            int x=0;
           for(auto j:i){
               x^=j;
             t.push_back(x);
           }
          a.push_back(t);
        }
        // for(auto i:a){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        int t=0;
         for(int i=0;i<matrix.size();i++){
             for(int j=0;j<matrix[i].size();j++){
                 if(i==0 and j!=0) 
                 t=(a[0][j]);
                 else if(i!=0 and j==0)
                 t=(a[i-1][0]^a[i][0]);
                 else if(i==0 and j==0)
                 t=(a[0][0]);
                 else
                 t=(a[i-1][j]^a[i][j]);
                 a[i][j]=t;
                 p.push(t);
             }
        }
       while(--k){
           p.pop();
       }
       return p.top();
    }
};