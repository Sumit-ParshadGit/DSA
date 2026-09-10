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
    bool sol(TreeNode* root){
        int s = 0;

        queue<TreeNode*>q;
        int c =0;
        q.push(root);
        while(!q.empty()){
            TreeNode*t = q.front();
            q.pop();
            s+=t->val;
            c++;
            if(t->left){
                q.push(t->left);
            }
            if(t->right){
                q.push(t->right);
            }
        }
        int t =s/c;
        if(root->val==t)return 1;
        return 0;
    }
    int averageOfSubtree(TreeNode* root) {
        queue<TreeNode*>q;
        int c =0;
        q.push(root);
        while(!q.empty()){
            TreeNode*t = q.front();
            q.pop();
            if(sol(t))c++;
            if(t->left){
                q.push(t->left);
            }
            if(t->right){
                q.push(t->right);
            }
        }return c;
    }
};