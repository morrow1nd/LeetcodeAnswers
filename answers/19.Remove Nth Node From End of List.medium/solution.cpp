/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* a = head;
        ListNode* b = head;
        
        for(; n > 0; --n) b = b->next;
        
        if(b == NULL) return head->next;
        
        for(b = b->next; b != NULL; b = b->next){
            a = a->next;
        }
        
        if(a->next) a->next = a->next->next;
        return head;
    }
};