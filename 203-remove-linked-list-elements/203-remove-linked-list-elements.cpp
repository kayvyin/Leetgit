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
  ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        ListNode* toDel;
        //handlig the deleton of head seperately
        while(head != NULL && head->val == val) {
            toDel = head;
            head = head->next;
            delete toDel;
        }
        //taking new node to retain the orginal head at the head
        ListNode* temp = head;
        while(temp && temp->next) {
            if(temp->next->val == val) {
                toDel = temp->next;
                temp->next = temp->next->next;
                delete toDel;
            }
            else
                temp = temp->next;
        }
        return head;
    }
  };