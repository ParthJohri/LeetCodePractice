class Solution {
public:
    int minMoves(int target, int maxDoubles) {
       int x=1,count=0;
       while(x<target)
       {
            if(target%2==0 && maxDoubles)
            {
                target/=2;
                maxDoubles--;
            }
           else if (maxDoubles==0)
             {  
               count+=target-x;
               target-=count;
               continue;
             }
           else
               target--;
           count++;
       }
        return count;
    }
};