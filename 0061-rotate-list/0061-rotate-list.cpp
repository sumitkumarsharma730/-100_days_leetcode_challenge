class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;

        ListNode* temp = head;

        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        if (n == 0 || k % n == 0) {
            return head;
        }

        k = k % n;

        int breakIdx = n - k;
        int i = 1;

        temp = head;

        while (i < breakIdx) {
            temp = temp->next;
            i++;
        }

        ListNode* newHead = temp->next;

        temp->next = nullptr;

        ListNode* tail = newHead;

        while (tail->next != nullptr) {
            tail = tail->next;
        }

        tail->next = head;

        return newHead;
    }
};