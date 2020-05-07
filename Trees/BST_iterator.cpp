/*
BST Iterator
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST. The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.
 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. Try to optimize the additional space complexity apart from the amortized time complexity.
 */

 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack <int> st;
void inorder(TreeNode *root)
{
    if(root == NULL)
        return;
    inorder(root->right);
    st.push(root->val);
    inorder(root->left);
}
BSTIterator::BSTIterator(TreeNode *root) {
    inorder(root);
}
static int i = 0;
/** @return whether we have a next smallest number */
bool BSTIterator::hasNext()
{
    return !st.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    int temp = st.top();
    st.pop();
    return temp;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
