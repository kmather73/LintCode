The idea is to maintain a BST of K the elements in each window. When the window moves to the right we just remove the last element and add the new element, this can be done in log k time if the tree is balanced, then extract the max element.

In C++ std::map is implemented as a red-black tree so we just us it to store the elements instead of implementing our own balanced tree.