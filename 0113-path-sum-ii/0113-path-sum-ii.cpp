/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>>ans;
    vector<int>tmp;
    void dfs(TreeNode* root, int ts,int s){
        if(!root){
            return ;
        }
        tmp.push_back(root->val);
        if(!root->left&&!root->right&&(s+root->val==ts))ans.push_back(tmp);
        dfs(root->left,ts,s+root->val);
        dfs(root->right,ts,s+root->val);
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int ts) {
        dfs(root,ts,0);
        return ans;
    }
};