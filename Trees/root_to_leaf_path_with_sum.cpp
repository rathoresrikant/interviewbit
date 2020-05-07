/*
Root to Leaf Paths With Sum
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum. For example: Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
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

vector <vector <int> > res;
stack <int> st;
void inorder(TreeNode *root, int B)
{
    if(root == NULL)
        return;
    st.push(root->val);
    inorder(root->left, B);
    if(!root->left && !root->right)
    {
        int n = st.size(), sum = 0;
        vector <int> temp;
        while(!st.empty())
        {
            temp.push_back(st.top());
            sum += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        for(int i=0; i<n; i++)
            st.push(temp[i]);
        if(sum == B)
            res.push_back(temp);
    }
    inorder(root->right, B);
    st.pop();
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B)
{
    while(!st.empty())
        st.pop();
    res.clear();
    inorder(A, B);
    return res;
}
