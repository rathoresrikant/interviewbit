/*
Palindrome List
Problem Description
Given a singly linked list A, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.


Problem Constraints
1 <= |A| <= 105


Input Format
The first and the only argument of input contains a pointer to the head of the given linked list.


Output Format
Return 0, if the linked list is not a palindrome. Return 1, if the linked list is a palindrome.


Example Input
Input 1:
A = [1, 2, 2, 1]
Input 2:
A = [1, 3, 2]


Example Output
Output 1:
 1
Output 2:
 0
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    stack <int> st;
    ListNode *temp = A;
    while(temp != NULL)
    {
        st.push(temp->val);
        temp = temp->next;
    }
    temp = A;
    while(temp != NULL)
    {
        if(st.top() != temp->val)
        return 0;
        st.pop();
        temp = temp->next;
    }
    return 1;
}
