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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode *temp = head, *temp1 = head ;
        temp=temp->next;
        temp1->next=nullptr;
        while(temp){
            ListNode* next = temp->next;
            temp->next=temp1;
            temp1=temp;
            temp=next;
        }
        return temp1;
    }
};
