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
private:
    ListNode* getkth(ListNode* cur, int k){
        k--;
        ListNode* t = cur;
       while(t && k){
        t=t->next;
        k--;
       }
       return t;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
        int p =k;
        ListNode* prev=nullptr;
        ListNode* cur=head;
        ListNode* res=head;
        bool isFirst = true;
      
        while(cur){
            ListNode* k = getkth(cur, p);
            ListNode* nextframe;
            if(k)nextframe = k->next;
            else nextframe = nullptr;
            ListNode* beg = cur;
            ListNode* temp = nullptr;
            prev = nullptr;
            while(beg){
               temp = beg;
               beg=beg->next;
               temp->next=prev;
               prev=temp;
               if(beg==k){beg->next=prev;break;}
            }
            if(isFirst){
                res = k;
                isFirst = false;
            }
            if(getkth(nextframe, p)){
                cur->next = getkth(nextframe, p);
            }else{
                cur->next=nextframe;
                return res;
            }
             cur = nextframe;
        }
        return res;
    }
};

















