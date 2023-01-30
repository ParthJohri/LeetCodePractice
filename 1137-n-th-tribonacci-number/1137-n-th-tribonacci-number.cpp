class Solution {
public:
    int tribonacci(int n) {
        int fb[n+5];
        fb[0]=0;
        fb[1]=1;
        fb[2]=1;
        for(int i=3;i<=n;i++){
            fb[i]=fb[i-1]+fb[i-2]+fb[i-3];

        }
        return fb[n];
    }
};