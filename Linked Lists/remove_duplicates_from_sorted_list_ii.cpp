/*
Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. For example, Given 1->2->3->3->4->4->5, return 1->2->5. Given 1->1->1->2->3, return 2->3.
*/
ListNode* Solution::deleteDuplicates(ListNode* A)
{
    if(A == NULL || A->next == NULL)
        return A;
   ListNode *curr = A;
   vector <int> res;
   unordered_map <int, int> mp;
   while(curr != NULL)
   {
       res.push_back(curr->val);
       mp[curr->val]++;
       curr = curr->next;
   }
   int n = res.size();
   vector <int> temp;
   for(int i=0; i<n; i++)
   {
       if(mp[res[i]] == 1)
            temp.push_back(res[i]);
   }
   n = temp.size();
   if(n > 0)
   {
        ListNode *newhead = new ListNode(temp[0]);
        curr = newhead;
        for(int i=1; i < n; i++)
        {
            curr->next = new ListNode(temp[i]);
            curr = curr->next;
        }
        curr = NULL;
        return newhead;
   }
   else
        return NULL;
}
