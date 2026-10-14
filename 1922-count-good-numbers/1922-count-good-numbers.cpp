
class Solution {
public:

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b % 2 == 1) {
                ans = (ans * a) % 1000000007;
            }

            a = (a * a) % 1000000007;
            b /= 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long ans = power(5, even) * power(4, odd) % 1000000007;

        return (int)ans;
    }
};
