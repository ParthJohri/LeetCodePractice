class Solution {
#define pp pair<int,int>
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pp,vector<pp>,greater<pp>>p;
        vector<int> ans;
        long long index=0,n=tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        long long time=tasks[0][0];
        while(!p.empty() or index<n){
            while(index<n and time>=tasks[index][0]){
                p.push({tasks[index][1],tasks[index][2]});
                index++;
            }
            if(p.empty()){
                time=tasks[index][0];
            } 
            else{
                ans.push_back(p.top().second);
                time+=p.top().first;
                p.pop();
            }
        }
        return ans;
    }
};