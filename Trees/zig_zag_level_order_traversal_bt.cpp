/*
ZigZag Level Order Traversal BT
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between). Example : Given binary tree
    3
   / \
  9  20
    /  \
   15   7
return
[
         [3],
         [20, 9],
         [15, 7]
]
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A)
{
    int level = 0;
    queue <TreeNode*> q;
    vector <vector <int> > res;
    q.push(A);
    while(!q.empty())
    {
        int m = q.size();
        vector <int> temp;
        TreeNode *curr;
        if(level%2 == 0) // left to right
        {
            stack <TreeNode *> st;
            while(m--)
            {
                curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left)
                    st.push(curr->left);
                if(curr->right)
                    st.push(curr->right);
            }
            while(!st.empty())
            {
                q.push(st.top());
                st.pop();
            }
            res.push_back(temp);
        }
        else            // right to left
        {
            stack <TreeNode *> st;
            while(m--)
            {
                curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->right)
                    st.push(curr->right);
                if(curr->left)
                    st.push(curr->left);
            }
            while(!st.empty())
            {
                q.push(st.top());
                st.pop();
            }
            res.push_back(temp);
        }
        level++;
    }
    return res;
}
