class Solution {
public:
    double myPow(double x, int n) {

        long long bin=n;
        double ans = 1;

        if (n==0) return 1;
        if (n==1) return x;
        if (x==0) return 0;
        if (x==1) return 1;
        if (x==-1 && n%2==1) return -1;
        if (x==-1 && n%2==0) return 1;

        if (n<0){
            x=1/x;
            bin=-bin;
        }

        while (0<bin){
            if (bin%2 != 0){
                ans*=x;
            }
            bin/=2;
            x*=x;
        }
        return ans;
    }
};