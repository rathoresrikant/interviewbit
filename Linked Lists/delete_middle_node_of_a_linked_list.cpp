/*
Delete middle node of a Linked List
Given a singly linked list, delete middle of the linked list. For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5 If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6. Return the head of the linked list after removing the middle node. If the input linked list has 1 node, then this node should be deleted and a null node should be returned.
Input Format
The only argument given is the node pointing to the head node of the linked list
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    // Count the number of nodes
    ListNode *temp = A, *head = NULL;
    int n = 0, pos;
    while(temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    if(n == 1)
        return head;
    //If n is odd we have to delete the (n+1)/2 th node
    if(n%2 == 1)
        pos = (n+1)/2;
    else
        pos = (n/2) + 1;
    // Store the pointer of the previous node
    ListNode *prev = A;
    int count = 0;
    while(prev != NULL)
    {
        count++;
        if(count == pos - 1)
        break;
        prev = prev->next;
    }
    prev->next = prev->next->next;
    return A;
}
