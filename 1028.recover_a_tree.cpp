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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> stack; 

        int i = 0;
        while(i < traversal.size()) {
            int depth = 0;

            while(i < traversal.size() && traversal[i] == '-') {
                depth++;
                i++;
            }

            int val = 0;
            while(i < traversal.size() && isdigit(traversal[i])) {
                val = val * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(val);

            while(stack.size() > depth)
                stack.pop_back();

            if(!stack.empty()) {
                TreeNode* parent = stack.back();
                if (!parent->left) parent->left = node;
                else parent->right = node;
            }
            stack.push_back(node);
        }
        return stack[0];
    }
};