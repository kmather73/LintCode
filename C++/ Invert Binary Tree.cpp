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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        invertBinaryTreeUtill(root);
    }
    
    
    TreeNode* invertBinaryTreeUtill(TreeNode *root) {
        if(root == NULL)
            return NULL;
            
        auto right = invertBinaryTreeUtill( root->left );
        root->left = invertBinaryTreeUtill( root->right );
        root->right = right;
        
        return root;
    }
};
