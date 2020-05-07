/*
Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values. Example : Given binary tree
   1
    \
     2
    /
   3
return [1,3,2]. Using recursion is not allowed.
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
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack <TreeNode *> st;
    TreeNode *curr = A;
    vector <int> res;
    while(curr != NULL || !st.empty())
    {
        while(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        if(curr == NULL && !st.empty())
        {
            res.push_back(st.top()->val);
            curr = st.top()->right;
            st.pop();
        }
    }
    return res;
}
