/*
Max Sum Path in Binary Tree
Given a binary tree T, find the maximum path sum. The path may start and end at any node in the tree. Input Format:
The first and the only argument contains a pointer to the root of T, A.
Output Format:
Return an integer representing the maximum sum path.
Constraints:
1 <= Number of Nodes <= 7e4
-1000 <= Value of Node in T <= 1000
Example :
Input 1:

       1
      / \
     2   3

Output 1:
     6

Explanation 1:
    The path with maximum sum is: 2 -> 1 -> 3

Input 2:

       -10
       /  \
     -20  -30

Output 2:
    -10

Explanation 2
    The path with maximum sum is: -10
*/
int maxPath(TreeNode *root, int &sum)
{
    if(!root)
        return 0;
    int left = maxPath(root->left, sum);
    int right = maxPath(root->right, sum);
    int maxs = max(max(left, right) + root->val, root->val);
    int maxt = max(maxs, left + right + root->val);
    sum = max(maxt, sum);
    return maxs;
}
int Solution::maxPathSum(TreeNode* A)
{
    int ans = INT_MIN;
    maxPath(A, ans);
    return ans;
}
