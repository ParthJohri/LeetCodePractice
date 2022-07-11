class Solution {
public:
    int countStudents(vector<int>& stud, vector<int>& sand) {
        stack<int> s;
        queue<int> q;
        reverse(sand.begin(),sand.end());
        
        for(auto i:sand) s.push(i);
        for(auto i:stud) q.push(i);    
        
        int c=0;
        
        while(!q.empty() && c<q.size()) {
            int student=q.front();
            q.pop();
            if(student==s.top()) {
                s.pop();
                c=0;
            }
            else {
                q.push(student);
                c++;
            }
        }
        return q.size();
    }
};