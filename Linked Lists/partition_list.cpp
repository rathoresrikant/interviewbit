/*
Partition List
Problem Description
 Given a linked list A and a value B, partition it such that all nodes less than B come before nodes greater than or equal to B. You should preserve the original relative order of the nodes in each of the two partitions.


Problem Constraints
1 <= |A| <= 106 1 <= A[i], B <= 109


Input Format
The first argument of input contains a pointer to the head to the given linked list. The second argument of input contains an integer, B.


Output Format
Return a pointer to the head of the modified linked list.


Example Input
Input 1:
A = [1, 4, 3, 2, 5, 2]
B = 3
Input 2:
A = [1, 2, 3, 1, 3]
B = 2


Example Output
Output 1:
[1, 2, 2, 4, 3, 5]
Output 2:
[1, 1, 2, 3, 3]


Example Explanation
In the first example, [1, 2, 2] are less than B wheread [4, 3, 5] are greater than or equal to B. In the second example, [1, 1] are less than B wheread [2, 3, 3] are greater than or equal to B.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B)
{
   ListNode *curr = A;
   ListNode *lesshead = new ListNode(0);
   ListNode *greaterhead = new ListNode(0);
   ListNode *less = lesshead, *greater = greaterhead;
   while(curr)
   {
       if(curr->val < B)
       {
           less->next = new ListNode(curr->val);
           less = less->next;
       }
       else
       {
           greater->next = new ListNode(curr->val);
           greater = greater->next;
       }
       curr = curr->next;
   }
   greater->next = NULL;
   less->next = greaterhead->next;
   return lesshead->next;
}
