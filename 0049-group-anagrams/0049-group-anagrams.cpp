class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto&wrd:strs){
            string tmp = wrd;
            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(wrd);
        }
        for(auto&[f,s]:mp){
            ans.push_back(s);
        }return ans;
    }
};