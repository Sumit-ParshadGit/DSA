class Solution {
public:
    string res = "";
    bool sol(vector<int>&cnt,string&t,string&tmp,int i,bool f){
        if(i>=t.size()){
            if(f)
            res = tmp;
            return f;
        }
        for(char ch = 'a';ch<='z';ch++){
            if(cnt[ch-'a']==0||ch<t[i]&&!f)continue;
            tmp.push_back(ch);
            cnt[ch-'a']--;
            bool nf = f||ch>t[i];
            if(sol(cnt,t,tmp,i+1,nf))
            return 1;

            tmp.pop_back();
            cnt[ch-'a']++;
        }return 0;
    }
    string lexGreaterPermutation(string s, string t) {
        vector<int>cnt(26,0);
        for(auto&el:s){
            cnt[el-'a']++;
        }
        string tmp = "";
        bool ans  = sol(cnt,t,tmp,0,0);
        return res;
    }
};