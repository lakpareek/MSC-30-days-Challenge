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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int x = maxDepth(root->left);
        int y = maxDepth(root->right);
        return max(x,y)+1;

    }


    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int x = maxDepth(root->left);
        int y = maxDepth(root->right);

        bool a = isBalanced(root->left);
        bool b = isBalanced(root->right);
        if(a && b && abs(x-y) <= 1){
            return true;
        }
        return false;
        
    }
};
