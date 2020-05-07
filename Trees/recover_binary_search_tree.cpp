/*
Recover Binary Search Tree
Two elements of a binary search tree (BST) are swapped by mistake. Tell us the 2 values swapping which the tree will be restored.
 Note: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
Example :
Input :
         1
        / \
       2   3

Output :
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be
         2
        / \
       1   3
which is a valid BST
*/
vector <int> res;
void inorder(TreeNode *A)
{
    if(A == 0)
        return;
    inorder(A->left);
    res.push_back(A->val);
    inorder(A->right);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    res.erase(res.begin(), res.end());
    inorder(A);
    int n = res.size();
    vector <int> ans;
    for(int i=n-2; i>=0; i--)
    {
        if(res[i] > res[i+1])
        {
            ans.push_back(res[i+1]);
            break;
        }
    }
    for(int i=1; i<n; i++)
    {
        if(res[i] < res[i-1])
        {
            ans.push_back(res[i-1]);
            break;
        }
    }
    return ans;
}
