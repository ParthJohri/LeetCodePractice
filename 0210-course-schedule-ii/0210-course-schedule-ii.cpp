class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans, indegree(numCourses);
        vector<int> adj[numCourses];
        queue<int> q;
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            for(auto i:adj[val]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
            ans.push_back(val);
            count++;
        }
        if(count!=numCourses) return vector<int>();
        return ans;
    }
};