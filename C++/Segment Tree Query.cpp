/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        if(root->start == start && root->end == end)
            return root->max;
            
        int leftEnd = (root->end + root->start)/2;
        int rightStart = leftEnd + 1;
        
        if(start >= rightStart)
            return query(root->right, start, end);
        else if( end <= leftEnd)
            return query(root->left, start, end);
        else
            return std::max(
                            query(root->left, start, leftEnd), 
                            query(root->right, rightStart, end) 
                            );
    }
};
