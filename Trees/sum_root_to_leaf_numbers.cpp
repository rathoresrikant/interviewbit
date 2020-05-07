/*
Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number. An example is the root-to-leaf path 1->2->3 which represents the number 123. Find the total sum of all root-to-leaf numbers % 1003. Example :
    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12. The root-to-leaf path 1->3 represents the number 13. Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.
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
long long res = 0, MOD = 1003;
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
        long long sum = 0;
        while(!st.empty())
        {
            int rem = st.top();
            temp.push_back(rem);
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        for(int i=0; i<n; i++)
        {
            st.push(temp[i]);
            sum = ((sum*10)%MOD + (temp[i])%MOD)%MOD;
        }
        res = (res%1003 + sum%1003)%1003;
    }
    inorder(root->right);
    st.pop();
}
int Solution::sumNumbers(TreeNode* A)
{
    res = 0;
    while(!st.empty())
        st.pop();
    inorder(A);
    return res%1003;
}
