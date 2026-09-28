/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        unordered_map<Node*, Node*>mp;
        Node* head3 = head;
        Node* copy = new Node(head->val);
        Node* head2 = copy;
        mp[head] = copy;
        head=head->next;
        while(head){
            copy->next = new Node(head->val);
            copy=copy->next;
            mp[head] = copy; 
            head=head->next;
        }
        copy=head2;
        while(head3){
          if(head3->random!=nullptr)mp[head3]->random = mp[head3->random];
          else copy->random = nullptr;
          head3=head3->next;
          copy=copy->next;
        }
        return head2;
    }
};  
