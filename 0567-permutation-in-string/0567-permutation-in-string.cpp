class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>fs1(26,0);
        vector<int>fs2(26,0);
        for(auto&c:s1){
            fs1[c-'a']++;
        }
        int m = s1.length();
        int n = s2.length();
        int i = 0;
        int j = 0;
        if(m>n)return 0;
        while(j<n){
            fs2[s2[j]-'a']++;
            if(j-i+1>m){
                fs2[s2[i]-'a']--;
                i++;
            }
            if(fs1==fs2)return 1;
            j++;
        }return 0;
    }
};