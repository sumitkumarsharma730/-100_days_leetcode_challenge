class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        int n = 1;
        ListNode* tail = head;

        // Find length and tail
        while (tail->next != nullptr) {
            tail = tail->next;
            n++;
        }

        k = k % n;

        if (k == 0) {
            return head;
        }

        // Make circular linked list
        tail->next = head;

        int steps = n - k;
        ListNode* newTail = tail;

        while (steps > 0) {
            newTail = newTail->next;
            steps--;
        }

        ListNode* newHead = newTail->next;

        // Break circular linked list
        newTail->next = nullptr;

        return newHead;
    }
};