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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        ListNode* end1, *end2;
        int sum;
        while(n1 != NULL && n2 != NULL){
            sum = n1->val + n2->val;
            if(sum >= 10){
                n1->val = sum - 10;
                if(n1->next != NULL){
                    n1->next->val++;
                    if(n1->next->val >= 10)
                        _carry(n1->next);
                }else if(n2->next != NULL){
                    n2->next->val++;
                    if(n2->next->val >= 10)
                        _carry(n2->next);
                }else{ // n1->next == NULL && n2->next == NULL
                    n1->next = new ListNode(1);
                    return l1;
                }
            }else{
                n1->val = sum;
            }
            end1 = n1;
            end2 = n2;
            n1 = n1->next;
            n2 = n2->next;
        }
        if(n1 == NULL){
            end1->next = n2;
            end2->next = NULL;
        }
        return l1;
    }
    void _carry(ListNode* n2)
    {
        for(ListNode* n = n2; n != NULL; n = n->next){
            if(n->val >= 10){
                n->val -= 10;
                if(n->next == NULL){
                    n->next = new ListNode(1);
                    return;
                }else{
                    n->next->val++;
                }
            }else{
                return;
            }
        }
    }
};