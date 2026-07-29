// class Solution {
// public:
//     string smallestPalindrome(string s) {
//         int n = s.length();
//         // if(n==1)return s;
//         // if(n%2==0){
//         //     string s1 = s.substr(n/2);
//         //     string s2 = s.substr(n/2,n/2);
//         //     sort(s1.begin(),s1.end());
//         //     sort(s2.begin(),s2.end(), greater<char>());
//         //     return s1+s2;
//         // }
//         //     string s1 = s.substr(0,n/2);
//         //     string s2 = s.substr(n/2+1,n/2);
//         //     sort(s1.begin(),s1.end());
//         //     sort(s2.begin(),s2.end(), greater<char>());
//         //     return s1+s[n/2]+s2;
//         int mid = n/2;
//         sort(begin(s),begin(s)+mid);
//         for(int i  =0;i<mid;i++){
//             s[n-1-i] = s[i];
//         }return s;
//     }
// };

class Solution {
public:
    string rev(string s){
        reverse(s.begin(),s.end());
        return s;
    }
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int>arr(26,0);
        for(int i = 0;i<n/2;i++){
            arr[s[i]-'a']++;
        }
        string t ="";
        if(n%2!=0)t = s[n/2];
        string s1 = "";
        for(int i = 0;i<26;i++){
            string t(arr[i],char('a'+i));
            s1+=t;
        }
        string s2 = rev(s1);
        return s1+t+s2;
    }
};