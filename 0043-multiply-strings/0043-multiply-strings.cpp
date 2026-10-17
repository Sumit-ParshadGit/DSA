
class Solution {
public:
    unordered_map<int, char> mp;

    Solution() {
        for (int i = 0; i <= 9; i++) {
            mp[i] = char('0' + i);
        }
    }

    string mul(string &num1, char ch) {
        string ans = "";
        int c = 0;

        for (int i = num1.size() - 1; i >= 0; i--) {
            int d = (num1[i] - '0') * (ch - '0');
            d += c;

            char t = mp[d % 10];
            c = d / 10;

            ans = string(1, t) + ans;
        }

        if (c != 0) {
            ans = string(1, mp[c]) + ans;
        }

        return ans;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        if (num1.length() < num2.length())
            swap(num1, num2);

        reverse(num2.begin(), num2.end());

        int n1 = num1.size();
        int n2 = num2.size();

        int l = n1 + n2;
        int h = n2;

        vector<string> s(h, string(l, '0'));

        for (int i = 0; i < n2; i++) {
            if (num2[i] == '0')
                continue;

            string tmp = mul(num1, num2[i]);

            int j = tmp.size() - 1;
            int si = l - 1 - i;

            while (j >= 0) {
                s[i][si] = tmp[j];
                si--;
                j--;
            }
        }

        string ans = "";
        int carry = 0;

        for (int col = l - 1; col >= 0; col--) {
            int sum = carry;

            for (int row = 0; row < h; row++) {
                sum += s[row][col] - '0';
            }

            ans = char('0' + sum % 10) + ans;
            carry = sum / 10;
        }

        int pos = 0;
        while (pos < ans.size() - 1 && ans[pos] == '0')
            pos++;

        return ans.substr(pos);
    }
};
