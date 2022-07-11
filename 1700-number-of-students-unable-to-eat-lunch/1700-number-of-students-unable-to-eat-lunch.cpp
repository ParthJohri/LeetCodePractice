class Solution {
public:
    int countStudents(vector<int>& stud, vector<int>& sand) {
        stack<int> s;
        queue<int> q;
        
        for(int i=sand.size()-1;i>=0;i--) s.push(sand[i]);
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