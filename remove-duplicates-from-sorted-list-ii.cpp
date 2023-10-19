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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head ->next == NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* dummy = new ListNode(0);
        ListNode* curr2 = dummy;
        queue<int> q;
        while(curr != NULL){
            if(curr->next != NULL && curr->val == curr->next->val){
                int i = curr->val;
                while(curr != NULL && curr->val == i){
                    curr = curr-> next;
                }
            }
            else{
                q.push(curr->val);
                curr=curr->next;
            }
        }
        while(!q.empty()){
            curr2->next = new ListNode(q.front());
            q.pop();
            curr2=curr2->next;
        }
        return dummy->next;
    }
};