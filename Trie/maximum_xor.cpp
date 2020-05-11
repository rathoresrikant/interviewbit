/*
Maximum XOR
Problem Description
Given an array of integers A, find and return the maximum result of A[i] XOR A[j], where i, j are the indexes of the array.


Problem Constraints
1 <= length of the array <= 100000
0 <= A[i] <= 109


Input Format
The only argument given is the integer array A.


Output Format
Return an integer denoting the maximum result of A[i] XOR A[j].


Example Input
Input 1:
 A = [1, 2, 3, 4, 5]
Input 2:
 A = [5, 17, 100, 11]



Example Output
Output 1:
 7
Output 2:
 117



Example Explanation
Explanation 1:
 Maximum XOR occurs between element of indicies(0-based) 1 and 4 i.e. 2 ^ 5 = 7.
Explanation 2:
 Maximum XOR occurs between element of indicies(0-based) 1 and 2 i.e. 17 ^ 100 = 117.
 */

 lass trieNode
{
    public:
    trieNode *left;
    trieNode *right;
    trieNode()
    {
        left = NULL;
        right = NULL;
    }
};
long long power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}
void insert(long long num, trieNode *root)
{
    trieNode *curr = root;
    for(long long i=31; i>=0; i--)
    {
        long long b = (num&(1<<i));
        if(b == 0)
        {
            if(curr->left == NULL)
            {
                curr->left = new trieNode();
            }
            curr = curr->left;
        }
        else
        {
            if(curr->right == NULL)
            {
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
}
int find_max_xor(trieNode *root, vector <long long> &arr)
{
    trieNode *curr = root;
    long long max_xor = INT_MIN, n = arr.size();
    for(long long i=0; i<n; i++)
    {
        trieNode *curr = root;
        long long curr_xor = 0;
        for(long long j=31; j>=0; j--)
        {
            long long b = (arr[i]&(1<<j));
            if(b == 0)
            {
                if(curr->right)
                {
                    curr = curr->right;
                    curr_xor = curr_xor + power(2, j);
                }
                else
                curr = curr->left;
            }
            else
            {
                if(curr ->left)
                {
                    curr = curr->left;
                    curr_xor = curr_xor + power(2, j);
                }
                else
                    curr = curr->right;
            }
        }
        if(curr_xor > max_xor)
            max_xor = curr_xor;
    }
    return max_xor;
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    trieNode *root = new trieNode();
    vector <long long> arr(n);
    for(int i=0; i<n; i++)
        arr[i] = A[i];
    for(int i=0; i<n; i++)
    {
        insert(arr[i], root);
    }
    return find_max_xor(root, arr);
}
