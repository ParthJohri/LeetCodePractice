class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(auto i:asteroids)
        {
            if(i>0||s.empty())
                s.push(i);
            else
            {while(true)
            { if(s.top()<0)
                {s.push(i);
                break;}
                else if(s.top()==-i)
                {s.pop();
                break;}
                else if(s.top()>-i)
                {break;}
                else
                {
                    s.pop();
                    if(s.empty())
                    {
                        s.push(i);
                        break;
                    }
                }
            }
        }
        }
        int n=s.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[n-i-1]=s.top();
            s.pop();
        }
        return ans;
    }
};