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
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        return build(A, 0, A.size()-1);
    }


    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(std::vector<int>&A, int start, int end) {
        if(start > end)
            return NULL;
        else if(start == end)
            return new SegmentTreeNode(start, end, A[start]);
        
        
        SegmentTreeNode *root = new SegmentTreeNode(start, end , 0);
        root->left = build(A, start, (start+end)/2 );
        root->right = build(A, 1 + (start+end)/2,  end );
        root->max = std::max( root->left->max,  root->right->max);
        
        return root;   
    }
};
