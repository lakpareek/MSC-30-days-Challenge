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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* fwd = head -> next ;
        ListNode* curr = head;
        while(curr != NULL && curr->next != NULL){
            curr -> next = fwd ->next;
            fwd -> next = curr;
            if (prev == NULL) {
                head = fwd;
            } 
            else{
                prev->next = fwd;
            }
            prev = curr;
            curr = curr->next;
            if(curr != NULL){
                fwd = curr->next;
            }
        }
        return head;
    }
};
