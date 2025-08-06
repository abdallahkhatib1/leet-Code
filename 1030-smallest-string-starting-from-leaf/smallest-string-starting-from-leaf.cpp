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
    string smallestFromLeaf(TreeNode* root) {
        string ans = "~";

        function<void(TreeNode*, string)> dfs = [&](TreeNode* node, string current) {
            if (!node) return;
            current = char('a' + node->val) + current;
            if (!node->left && !node->right) {
                if (current < ans) {
                    ans = current;
                }
                return;
            }
            dfs(node->left, current);
            dfs(node->right, current);
        };

        dfs(root, "");
        return ans;
    }
};
