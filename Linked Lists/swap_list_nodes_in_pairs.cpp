/*
Swap List Nodes in pairs
Problem Description
Given a linked list A, swap every two adjacent nodes and return its head. NOTE: Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


Problem Constraints
1 <= |A| <= 106


Input Format
The first and the only argument of input contains a pointer to the head of the given linked list.


Output Format
Return a pointer to the head of the modified linked list.


Example Input
Input 1:
A = [1, 2, 3, 4]
Input 2:
A = [7, 2, 1]


Example Output
Output 1:
[2, 1, 4, 3]
Output 2:
[2, 7, 1]


Example Explanation
In the first example [[1, 2], [3, 4]] are the adjacent nodes. Swapping them will result in [2, 1, 4, 3]. In the second example, 3rd element i.e. 1 does not have an adjacent node, so it won't be swapped.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(A == NULL || A->next == NULL)
        return A;
    ListNode *curr = A->next->next;
    ListNode *prev = A;
    A = A->next;
    A->next = prev;
    while(curr != NULL && curr->next != NULL)
    {
        prev->next = curr->next;
        prev = curr;
        ListNode *nxt = curr->next->next;
        curr->next->next = curr;
        curr = nxt;
    }
    prev->next = curr;
    return A;
}
