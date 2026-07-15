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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* copy = root;
        TreeNode* newNode = new TreeNode(val);
        if(root == NULL) return newNode;
        while (copy != NULL) {
            if (val > copy->val){
                if(copy->right != NULL){
                    copy = copy->right;
                } else {
                    copy->right = newNode;
                    break;
                }
            } else {
                if(copy->left != NULL){
                    copy = copy->left;
                } else {
                    copy->left = newNode;
                    break;
                }
            }
        }
        return root;
    }
};