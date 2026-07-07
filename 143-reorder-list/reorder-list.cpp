class Solution {
public:

    ListNode* reversel(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *prev = NULL, *curr = head, *nex = NULL;

        while(curr != NULL) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        head = prev;
        return head;;
    }

    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode * slow = head, *fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL) slow = slow->next;
        ListNode* h2 = reversel(slow);

        ListNode* h1 = head;
        while(h2 != NULL) {
            ListNode *t1 = h1->next, *t2 = h2->next;
            h1->next = h2;
            h2->next = t1;
            h1 = t1;
            h2 = t2;
        }
        h1->next = NULL;

        return;
    }
};