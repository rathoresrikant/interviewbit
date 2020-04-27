/*
Detect and Remove Loop from a linked list
Given a linked list which contains some loop. You need to find the node, which creates a loop, and break it by making the node point to NULL. INPUT
3 -> 2 -> 4 -> 5 -> 6
          ^         |
          |         |
          - - - - - -
OUTPUT
3 -> 2 -> 4 -> 5 -> 6 -> NULL
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
    unordered_map <ListNode *, int> mp;
    ListNode *prev, *temp = A;
    while(temp != NULL)
    {
        if(mp[temp] != 0)
        {
            prev->next = NULL;
            break;
        }
        else
        {
            mp[temp]++;
        }
        prev = temp;
        temp = temp->next;
    }
    return A;
}
