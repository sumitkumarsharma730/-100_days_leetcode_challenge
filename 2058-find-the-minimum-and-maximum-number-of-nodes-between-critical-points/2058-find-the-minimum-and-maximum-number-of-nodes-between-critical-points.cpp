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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCritical = -1;
        int previousCritical = -1;

        int minDistance = INT_MAX;
        int index = 1;

        ListNode* previous = head;
        ListNode* current = head->next;

        while (current->next != nullptr) {

            bool isCritical =
                (current->val > previous->val &&
                 current->val > current->next->val) ||
                (current->val < previous->val &&
                 current->val < current->next->val);

            if (isCritical) {

                if (firstCritical == -1) {
                    firstCritical = index;
                }

                if (previousCritical != -1) {
                    minDistance = min(
                        minDistance,
                        index - previousCritical
                    );
                }

                previousCritical = index;
            }

            previous = current;
            current = current->next;
            index++;
        }

        // Fewer than two critical points
        if (firstCritical == previousCritical) {
            return {-1, -1};
        }

        int maxDistance = previousCritical - firstCritical;

        return {minDistance, maxDistance};
    }
};