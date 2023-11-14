/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty())
        {
            return NULL;
        }
        if (lists.size() == 1)
        {
            return lists[0];
        }
        
        int n = lists.size();
        while (n > 1) 
        {
          int m = (n + 1) / 2;
          for (int i = 0; i < n - m; i++) 
          {
            lists[i] = mergeTwoLists(lists[i], lists[i + m]);
          }
           n = m;
        }
        return lists[0];
    }

  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
  {
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    while (l1 != NULL && l2 != NULL) 
    {
      if (l1->val < l2->val) 
      {
        curr->next = l1;
        l1 = l1->next;
      } 
      else 
      {
        curr->next = l2;
        l2 = l2->next;
      }
      curr = curr->next;
    }
        curr->next = (l1 == NULL) ? l2 : l1;
        return head->next;
  }
};
