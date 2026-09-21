class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n = lists.size();

        vector<ListNode*> temp = lists;

        ListNode* ans = new ListNode();
        ListNode* tail = ans;

        while(true) {

            int minIndex = -1;

            for(int i = 0; i < n; i++) {

                if(temp[i] == NULL) {
                    continue;
                }

                if(minIndex == -1 ||
                   temp[i]->val < temp[minIndex]->val) {
                    minIndex = i;
                }
            }

            if(minIndex == -1) {
                break;
            }

            tail->next = temp[minIndex];
            tail = tail->next;

            temp[minIndex] = temp[minIndex]->next;
        }

        return ans->next;
    }
};