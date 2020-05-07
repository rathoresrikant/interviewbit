/*
Binary Tree Paths
Given a binary tree. Return all root to leaf paths. You can return the paths in any order. Note: A leaf is a node with no children. For Example
Input 1:
                57
               /  \
              77  76
             / \
            21  16
Output 1:
    [   [57, 76]
        [57, 77, 16]
        [57, 77, 21]    ]

Input 2:
                1
               / \
              2   3
             / \  / \
            4   5 6  7
Output 2:
     [  [1, 2, 4]
        [1, 2, 5]
        [1, 3, 6]
        [1, 3, 7]    ]
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
vector <vector <int>> res;
void inorder(TreeNode *A, stack <int> &st)
{
    if(A == NULL)
        return;
    st.push(A->val);
    inorder(A->left, st);
    if(!A->left && !A->right)
    {
        vector <int> temp;
        while(!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        res.push_back(temp);
        for(int i=0; i<temp.size(); i++)
            st.push(temp[i]);
    }
    inorder(A->right, st);
    st.pop();
}
vector<vector<int> > Solution::solve(TreeNode* A)
{
    res.clear();
    stack <int> st;
    inorder(A, st);
    return res;
}
