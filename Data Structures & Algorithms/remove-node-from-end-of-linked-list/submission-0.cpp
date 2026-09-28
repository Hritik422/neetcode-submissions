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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int tot=0;
      ListNode* temp = head;
      while(temp){
        temp=temp->next;
        tot++;
      }
      int m = tot-n+1;
      temp=head;
      if(m==1)return head->next;
      while(temp){
        if(m==2){
            temp->next=temp->next->next;
            return head;
        }
        m--;
        temp=temp->next;
      }
      return head;
    }
};
