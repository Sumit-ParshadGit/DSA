using namespace std;

class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        for (int i = 2; i <= 9; ++i) {
            while (temp % i == 0) temp /= i;
        }
        if (temp > 1) return "-1";
        
        int n = num.length();
        vector<long long> rem(n + 1, 0);
        rem[0] = t;
        int pos = n - 1;
        
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                pos = i;
                break;
            }
            rem[i + 1] = rem[i] / gcd(rem[i], (long long)(num[i] - '0'));
        }
        
        if (rem[n] == 1 && pos == n - 1 && num[pos] != '0') return num;
        
        for (int i = pos; i >= 0; --i) {
            int startDigit = (i < n) ? (num[i] - '0') + 1 : 1;
            for (int d = startDigit; d <= 9; ++d) {
                long long tNow = rem[i] / gcd(rem[i], (long long)d);
                string suffix = "";
                long long currT = tNow;
                
                for (int j = n - 1; j > i; --j) {
                    for (int v = 9; v >= 1; --v) {
                        if (currT % v == 0) {
                            suffix += to_string(v);
                            currT /= v;
                            break;
                        }
                    }
                }
                if (currT == 1) {
                    reverse(suffix.begin(), suffix.end());
                    return num.substr(0, i) + to_string(d) + suffix;
                }
            }
        }
        
        long long currT = t;
        string digits = "";
        for (int v = 9; v >= 2; --v) {
            while (currT % v == 0) {
                digits += to_string(v);
                currT /= v;
            }
        }
        sort(digits.begin(), digits.end());
        int reqLen = max(n + 1, (int)digits.length());
        return string(reqLen - digits.length(), '1') + digits;
    }
};