class Solution {
public:
    bool checkDivisibility(int n) {
        int t=n;
        int s=0;
        int p=1;
        while(n>0){
            int d=n%10;
            s=s+d;
            p*=d;
            n/=10;

        }

        return t%(s+p)==0;
        
    }
};