
// class Solution {
// public:
// string res = "";

//     bool sol(string &tmp,string &t,vector<int>&cnt,int ind,int f){
//         if(ind>=t.size()){
//             if(f){
//                 res = tmp;
//             }return f;
//         }
//         for(char ch = 'a';ch<='z';ch++){
//             if(cnt[ch-'a']<=0||ch<t[ind]&&!f)continue;
//             tmp.push_back(ch);
//             cnt[ch-'a']--;
//             int nf = f||ch>t[ind];
//             if(sol(tmp,t,cnt,ind+1,nf))
//             return 1;
//             tmp.pop_back();
//             cnt[ch-'a']++;
//         }return 0;
//     }
//     string lexPalindromicPermutation(string s, string t) {

//         int sz = s.size()/2+s.size()%2;
//         string nt = t.substr(0,sz);
//         vector<int>cnt(26,0);
//         for(char ch:s){
//             cnt[ch-'a']++;
//         }
//         int oc = 0;
//         for(auto&el:cnt){
//             if(el%2==1)oc++;
//         }if(oc>1)return "";
//         for(auto&el:cnt){
//             int t=el/2+el%2;
//             el = t;
//         }
//         string tmp = "";
//         if(!sol(tmp,nt,cnt,0,0))return "";
//         string rest = res;
//         if(s.size()%2==1)res.pop_back();
//         reverse(rest.begin(),rest.end());
//         return res+rest;
//     }
// };

// class Solution {
// public:
//     string lexGreaterPermutation(string s, string t) {
//         sort(s.begin(),s.end());
//         string s2 = s;
//         reverse(s2.begin(),s2.end());
//         if(s2<=t)return "";
//         while(s<=t){
//             next_permutation(s.begin(),s.end());
//         }
//         return s;
//     }
// };

class Solution {
public:
string res = "";
string cand = "";
    bool sol(string &tmp,string &t,vector<int>&cnt,int ind,int f){
        if(ind>=t.size()/2){
                string tmp2 = tmp;
                string tmp1 = tmp;
                reverse(tmp2.begin(),tmp2.end());
                tmp1+=cand;
                if((tmp1+tmp2)>t){
                res = tmp1+tmp2;
                return 1;}
            return 0;
        }
        for(char ch = 'a';ch<='z';ch++){
            if(cnt[ch-'a']<=0||ch<t[ind]&&!f)continue;
            tmp.push_back(ch);
            cnt[ch-'a']--;
            int nf = f||ch>t[ind];
            if(sol(tmp,t,cnt,ind+1,nf))
            return 1;
            tmp.pop_back();
            cnt[ch-'a']++;
        }return 0;
    }
    string lexPalindromicPermutation(string s, string t) {
        sort(s.begin(),s.end());
        string s2 = s;
        reverse(s2.begin(),s2.end());
        if(s2<=t)return "";
        vector<int>cnt(26,0);
        for(char ch:s){
            cnt[ch-'a']++;
        }
        int oc = 0;
        
        for(int el = 0;el<26;el++){
            if(cnt[el]%2==1){
                cand = 'a'+el;
                oc++;
            }
        }
        if(oc>1)return "";
        for(int &el:cnt){
            el/=2;
        }
        string tmp = "";
        bool re = sol(tmp,t,cnt,0,0);
        return res;
    }
};