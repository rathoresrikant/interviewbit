/*
Merge K Sorted Lists
Problem Description
Given a list containing head pointers of N sorted linked lists. Merge these N given sorted linked lists and return it as one sorted list.


Problem Constraints
1 <= total number of elements in given linked lists <= 100000


Input Format
First and only argument is a list containing N head pointers.


Output Format
Return a pointer to the head of the sorted linked list after merging all the given linked lists.


Example Input
Input 1:
 1 -> 10 -> 20
 4 -> 11 -> 13
 3 -> 8 -> 9
Input 2:
 10 -> 12
 13
 5 -> 6



Example Output
Output 1:
 1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
Output 2:
 5 -> 6 -> 10 -> 12 ->13



Example Explanation
Explanation 1:
 The resulting sorted Linked List formed after merging is 1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20.
Explanation 2:
 The resulting sorted Linked List formed after merging is 5 -> 6 -> 10 -> 12 ->13.
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
    sort(arr.begin(), arr.end());
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
