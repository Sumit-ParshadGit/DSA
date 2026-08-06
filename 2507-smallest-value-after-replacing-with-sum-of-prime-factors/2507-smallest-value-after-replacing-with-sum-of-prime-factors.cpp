class Solution {
public:
    bool is_prime(int n){
        for(int i = 2;i*i<=n;i++){
            if(n%i==0)return 0;
        }return 1;
    }
    int smallestValue(int n) {
        if(is_prime(n))return n;
        vector<int>primes;
        for(int i = 2;i<=n/2;i++){
            if(is_prime(i))primes.push_back(i);
        }
        while(1){
            int nn = n;
            int s = 0;
            
            if(is_prime(n))return n;
            for(auto&el:primes){
                while(nn&&nn%el==0){
                    s+=el;
                    nn/=el;
                }
            }
            if(s==n)return n;
            n =s;
        }return n;
    }
};