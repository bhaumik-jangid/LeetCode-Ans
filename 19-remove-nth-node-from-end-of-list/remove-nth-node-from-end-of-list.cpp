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
    int index = 0;
    int target;

    void deleteNode(ListNode*& curr){
        if(curr != NULL){
            deleteNode(curr->next);
        }
        if(index == target + 1){
            ListNode* toFree = curr->next;
            curr->next = curr->next->next;

            delete toFree;
        }
        index++;
    }

    int getlength(ListNode*& head){
        int len = 0;
        ListNode* copy = head;
        while(copy!=NULL){
            len++;
            copy = copy->next;
        }
        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        int len = getlength(head);
        if(len == n){
            head = head->next;
            return head;
        }
        target = n;
        ListNode* curr = head;
        deleteNode(curr);
        head = curr;
        return head;
    }
};