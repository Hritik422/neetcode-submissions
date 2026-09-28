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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)return list2;
        else if(!list2)return list1;
        if(list2->val<list1->val)swap(list1, list2);
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1->next && temp2){
            if(temp2->val>=temp1->val && temp2->val<=temp1->next->val){
                ListNode* cur = temp2;
                temp2=temp2->next;
                cur->next=temp1->next;
                temp1->next=cur;
                temp1=cur;
            }else{
                temp1=temp1->next;
            }
        }
        while(temp1->next)temp1=temp1->next;
        temp1->next = temp2;
        return list1;
    }
};
