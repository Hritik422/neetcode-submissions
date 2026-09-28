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
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* cur = NULL;
        while(temp){
            cur = temp;
            temp=temp->next;
            cur->next = prev;
            prev = cur;
            if(!temp)return prev;
        }
        return NULL;
    }
};
