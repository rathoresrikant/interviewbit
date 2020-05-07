/*
Vertical Order traversal of Binary Tree
Given a binary tree, return a 2-D array with vertical order traversal of it. Go through the example and image for more details. Example : Given binary tree:
      6
    /   \
   3     7
  / \     \
 2   5     9
returns
[
    [2],
    [3],
    [6 5],
    [7],
    [9]
]
 Note : If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.
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

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector <vector <int> > res;
    if(A == NULL)
        return res;
    map <int, vector <int> > mp;
    queue <pair<TreeNode *, int> > q;
    q.push(make_pair(A, 0));
    while(!q.empty())
    {
        TreeNode *curr = q.front().first;
        int idx = q.front().second;
        mp[idx].push_back(curr->val);
        q.pop();
        if(curr->left)
            q.push(make_pair(curr->left, idx - 1));
        if(curr->right)
            q.push(make_pair(curr->right, idx + 1));
    }
    int k = 0;
    for(auto it : mp)
    {
        int n = it.second.size();
        vector <int> temp;
        for(int i=0; i<n; i++)
            temp.push_back(it.second[i]);
        res.push_back(temp);
    }
    return res;
}
