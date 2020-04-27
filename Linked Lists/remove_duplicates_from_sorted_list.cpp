/*
Remove Duplicates from Sorted List
Problem Description
Given a sorted linked list, delete all duplicates such that each element appear only once.


Problem Constraints
0 <= length of linked list <= 1000000


Input Format
First argument is the head pointer of the linked list.


Output Format
Return the head pointer of the linked list after removing all duplicates.


Example Input
Input 1:
1->1->2
Input 2:
1->1->2->3->3



Example Output
Output 1:
1->2
Output 2:
1->2->3



Example Explanation
Explanation 1:
each element appear only once in 1->2.



You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a doubt? Checkout Sample Codes for more details.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A)
{
    if(A == NULL)
        return NULL;
    ListNode *curr = A;
    while(curr->next != NULL)
    {
        if(curr->val == curr->next->val)
        {
            ListNode *temp = curr->next;
            curr->next = temp->next;
            delete(temp);
        }
        else
        {
            curr = curr->next;
        }
    }
    return A;
}
