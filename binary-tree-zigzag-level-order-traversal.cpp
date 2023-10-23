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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        vector<vector<int>> ans;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelValues(levelSize);

            for (int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();

                int index;
                if (flag) {
                    index = i;
                } else {
                    index = levelSize - i - 1;
                }

                levelValues[index] = temp->val;

                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }

            ans.push_back(levelValues);
            flag = !flag;
        }

        return ans;
    }
};
