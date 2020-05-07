/*
Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values. Example : Given binary tree
   1
    \
     2
    /
   3
return [1,2,3]. Using recursion is not allowed.
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
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector <int> res;
    stack <TreeNode *> s;
    s.push(A);
    while(!s.empty())
    {
        TreeNode *temp = s.top();
        s.pop();
        res.push_back(temp->val);
        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);
    }
    return res;
}
