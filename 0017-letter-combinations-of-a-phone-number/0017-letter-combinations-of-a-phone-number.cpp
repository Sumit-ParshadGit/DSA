class Solution {
public:
vector<string>ans;
    unordered_map<char,string>mp;
    Solution(){
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
    }
    void sol(string &digits,string &tmp,int i){
        if(i>=digits.size()){
           ans.push_back(tmp);
            return;
        }
        for(char ch:mp[digits[i]]){
            tmp.push_back(ch);
            sol(digits,tmp,i+1);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string tmp = "";
        sol(digits,tmp,0);
        return ans;
    }
};