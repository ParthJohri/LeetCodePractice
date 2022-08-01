class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        if(grades.size()<=2) return 1;
        sort(grades.begin(),grades.end());
        int count=1,sum=grades[0],i=1,x=2;
        vector<long long int> gr(grades.size(),0);
        gr[0]=grades[0];
        for(int i=1;i<grades.size();i++){
            gr[i]=grades[i]+gr[i-1];
        }
        while(i<grades.size()){
            if(gr[i+x-1]-gr[i-1]>sum){
                sum=gr[i+x-1]-gr[i-1];
                count++;
            }
            i+=x;
            x++;
            if(x>grades.size()-i)
                break;
        }
        return count;
    }
};