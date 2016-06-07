/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @aaram a, b, the root of binary trees.
     * @return true if they are identical, or false.
     */
    bool isIdentical(TreeNode* a, TreeNode* b) {
        if(a == nullptr && b == nullptr) return true;
        else if(a == nullptr || b == nullptr) return false;
        else if(a->val != b->val) return false;
        
        return isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
        
    }
};