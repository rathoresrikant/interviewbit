/*
Populate Next Right Pointers Tree
Given a binary tree
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL. Initially, all next pointers are set to NULL.
 Note:
You may only use constant extra space.
Example : Given the following binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
 Note 1: that using recursion has memory overhead and does not qualify for constant space. Note 2: The tree need not be a perfect binary tree.
 */

 /**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode *temp = A;
    queue <TreeLinkNode *> q;
    q.push(temp);
    while(!q.empty())
    {
        TreeLinkNode *prev = q.front();
        q.pop();
        int m = q.size();
        if(prev->left)
            q.push(prev->left);
        if(prev->right)
            q.push(prev->right);
        while(m--)
        {
            TreeLinkNode *curr = q.front();
            q.pop();
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            prev->next = curr;
            prev = curr;
        }
        prev->next = NULL;
    }
}
