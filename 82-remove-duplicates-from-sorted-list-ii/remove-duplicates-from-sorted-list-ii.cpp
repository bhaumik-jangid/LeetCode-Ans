class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy, *curr = head;

        while(curr != NULL && curr->next != NULL) {
            if(curr->val == curr->next->val) {
                while(curr->next != NULL && (curr->val == curr->next->val)) {
                    curr->next = curr->next->next;
                }
                curr = curr->next;
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};