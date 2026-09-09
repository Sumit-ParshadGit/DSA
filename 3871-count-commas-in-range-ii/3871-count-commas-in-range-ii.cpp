class Solution {
public:
typedef long long ll;
    long long countCommas(long long n) {
        ll ans = 0;
        ll t = 1e3;
        for(int i = 3;i<=15;i+=3){
            ll d = n - t+1;
            if(d<=0)break;
            ans +=d;
            t*=1000;
        }
        return ans;
    }
};