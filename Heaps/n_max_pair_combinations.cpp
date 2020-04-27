/*
N max pair combinations
Problem Description
Given two integers arrays A and B of size N each. Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.


Problem Constraints
1 <= N <= 2 * 105 -1000 <= A[i], B[i] <= 1000


Input Format
First argument is an integer array A.
Second argument is an integer array B.


Output Format
Return an intger array denoting the N maximum element in descending order.


Example Input
Input 1:
 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
Input 2:
 A = [2, 4, 1, 1]
 B = [-2, -3, 2, 4]


Example Output
Output 1:
 [10, 9, 9, 8]
Output 2:
 [8, 6, 6, 5]


Example Explanation
Explanation 1:
 4 maximum elements are 10(6+4), 9(6+3), 9(5+4), 8(6+2).
Explanation 2:
 4 maximum elements are 8(4+4), 6(4+2), 6(4+2), 5(4+1).
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    int n = A.size();
    vector <int> arr;
    for(int i=0; i<n; i++)
    {
        ListNode *curr = A[i];
        while(curr != NULL)
        {
            arr.push_back(curr->val);
            curr = curr->next;
        }
    }
    n = arr.size();
    ListNode *root = new ListNode(arr[0]);
    ListNode *head = root;
    for(int i=1; i<n; i++)
    {
        root->next = new ListNode(arr[i]);
        root = root->next;
    }
    root->next = NULL;
    return head;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B)
{
    vector <int> res;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue <pair<int, pair<int,int>>> pq;
    int n = A.size();
    int sum = A[n-1] + B[n-1];
    set <pair<int,int>> s;
    pq.push(make_pair(sum, make_pair(n-1,n-1)));
    while(res.size() < n)
    {
        pair<int, pair<int,int>> curr = pq.top();
        pq.pop();
        res.push_back(curr.first);
        int n1 = curr.second.first;
        int n2 = curr.second.second;
        pair <int,int> temp = make_pair(n1-1,n2);
        sum = A[n1-1] + B[n2];
        if(s.find(temp) == s.end())
        {
            pq.push(make_pair(sum, make_pair(n1-1,n2)));
            s.insert(temp);
        }
        sum = A[n1] + B[n2-1];
        temp = make_pair(n1,n2-1);
        if(s.find(temp) == s.end())
        {
            pq.push(make_pair(sum, make_pair(n1,n2-1)));
            s.insert(temp);
        }
    }
    return res;
}
