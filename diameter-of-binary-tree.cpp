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
        if(root == NULL){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int a = maxDepth(root->left);
        int b = maxDepth(root->right);
        int rootDiameter = a + b;
        int leftSubtreeDiameter = diameterOfBinaryTree(root->left);
        int rightSubtreeDiameter = diameterOfBinaryTree(root->right);
        return max(rootDiameter, max(leftSubtreeDiameter, rightSubtreeDiameter));
    }
};
