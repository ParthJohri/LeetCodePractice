class Solution {
public:
    vector<int> stackPreviousSmaller(vector<int>&heights){
        int n=heights.size();
        vector<int>prevSmaller(n,-1);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() and heights[s.top()]>heights[i]){
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
        vector<int> nextSmaller(n,n);
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
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> prevSmall,nextSmall;
        int length=arr.size();
        long long ans=0,mod=1e9+7;
        prevSmall=stackPreviousSmaller(arr);
        nextSmall=stackNextSmaller(arr);
        for(int i=0;i<length;i++){
            int l=i-prevSmall[i],r=nextSmall[i]-i;
            long long val=l*1ll*r;
            ans=(ans+val*1ll*arr[i])%mod;
            cout<<(val*arr[i])<<endl;
        }
        return ans;
    }
};