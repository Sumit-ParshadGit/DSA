class Solution {
public:
    long long ncr(int n,int r,int k){
        int res = 1;
        r = min(r,n-r);
        for(int i = 1;i<=r;i++){
            res = res*(n-r+i)/i;
            if(res>=k)return k;
        }return res;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int>cnt(26,0);
        for(int i = 0;i<n/2;i++){
            cnt[s[i]-'a']++;
        }

        string s1 = "";
        for(int i = 0;i<n/2;i++){
            bool p = 0;
            for(int j = 0;j<26;j++){
                if(cnt[j]>0){
                    cnt[j]--;

                    long long ways = 1;
                    int letters = 0;
                    for(int c = 0;c<26;c++){
                        letters+=cnt[c];
                    }
                    for(int c = 0;c<26;c++){
                        if(cnt[c]>0){
                            ways*=ncr(letters,cnt[c],k);
                            letters-=cnt[c];
                        }
                        if(ways>=k){
                            p=1;
                            break;}
                    }
                    if(ways>=k){
                        s1.push_back(j+'a');
                        p = 1;
                        break;
                    }
                    k-=ways;
                    cnt[j]++;
                }
            }
            if(!p)return "";
        }
        string s2= s1;
        reverse(s2.begin(),s2.end());
        string t = "";
        if(n%2==1)t = s[n/2];
        return s1+t+s2;

    }
};