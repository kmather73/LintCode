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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        if(root == NULL)
            return NULL;
        else if( value < root->val)
            root-> left = removeNode(root->left, value);
        else if ( value  > root->val)
            root->right =  removeNode(root->right,  value);
        else if(root->val == value) {
        //Remove the root
            if(root->left != NULL){
                auto left = root->left;
                while(left->right != NULL)
                    left = left->right;
                
                left->right = root->right;
                root = root->left;
                
            } else {
                root =  root->right;
            }
        }
        return root;
    }
};
