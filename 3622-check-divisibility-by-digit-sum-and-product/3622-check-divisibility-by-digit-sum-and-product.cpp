class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int p=1;
        int t = n;
        while(n){
            int d=n%10;
            sum+=d;
            p*=d;
            n/=10;
        }
        return t%(sum+p)==0;
    }
};