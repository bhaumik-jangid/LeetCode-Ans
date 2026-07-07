class Solution {
public:

    ListNode* reverseL(ListNode* head) {
        if(head == NULL) return head;
        ListNode *prev = NULL, *curr = head, *nex = NULL;

        while(curr != NULL){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }        
        head = prev;
        return head;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode *slow = head, *fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *head2 = reverseL(slow);

        while(head2 != NULL) {
            if(head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }

        return true;


        // stack<int> s;

        // ListNode* temp = head;
        // while(temp != NULL) {
        //     s.push(temp->val);
        //     temp = temp->next;
        // }

        // temp = head;
        // while(temp != NULL) {
        //     if(s.top() != temp->val) return false;
        //     s.pop();
        //     temp = temp->next;
        // }

        // return true;;
    }
};