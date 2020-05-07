/*
Print all root to leaf paths
You are given a binary tree. Find all paths from root to leaves of the binary tree.
Input Format
The only argument given is the root pointer of tree A.
Output Format
Return all paths from root to leaf.
Constraints
1 <= number of nodes <= 50000
0 <= A[i] <= 10^9
For Example
Input 1:
          5
         / \
        4   8
       /   / \
      11  13  4
     /      /
    7      5
Output 1:
 [
   [5,4,11,7],
   [5,8,13],
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
void inorder(TreeNode *root)
{
    if(root == NULL)
        return;
    st.push(root->val);
    inorder(root->left);
    if(!root->left && !root->right)
    {
        int n = st.size();
        vector <int> temp;
        while(!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        for(int i=0; i<n; i++)
            st.push(temp[i]);
        res.push_back(temp);
    }
    inorder(root->right);
    st.pop();
}
vector<vector<int> > Solution::solve(TreeNode* A) {
    while(!st.empty())
        st.pop();
    res.clear();
    inorder(A);
    return res;
}
