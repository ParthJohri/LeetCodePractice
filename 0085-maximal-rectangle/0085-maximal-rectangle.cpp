class Solution {
public:
    vector<int> stackPreviousSmaller(vector<int>&heights){
        int n=heights.size();
        vector<int>prevSmaller(n,-1);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() and heights[s.top()]>=heights[i]){
                    s.pop();
            }
            if(s.empty()){
                prevSmaller[i]=-1;//start of array
            }
            else{
                prevSmaller[i]=s.top();
            }
            s.push(i);//pushing index of elements
        }
        return prevSmaller;
    }
    vector<int> stackNextSmaller(vector<int>&heights){
        int n=heights.size();
        vector<int> nextSmaller(n,-1);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                nextSmaller[i]=n;//end of array
            }
            else{
                nextSmaller[i]=s.top();
            }
            s.push(i);//pushing index of elements
        }
        return nextSmaller;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),ans=0;
        vector<int> prevSmaller(n,-1),nextSmaller(n,-1);
        prevSmaller=stackPreviousSmaller(heights);
        nextSmaller=stackNextSmaller(heights);
        for(int i=0;i<n;i++){
            int calculatedValue=(nextSmaller[i]-prevSmaller[i]-1)*heights[i];
            ans=max(ans,calculatedValue);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size(),ans=0;
        vector<int> heights(cols,0);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='1')
                    heights[j]+=1;
                else 
                    heights[j]=0;
            }
            int val=largestRectangleArea(heights);
            ans=max(ans,val);
        }
        return ans;
    }
};