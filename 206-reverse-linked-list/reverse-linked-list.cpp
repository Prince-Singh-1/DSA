class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *cur = head;

        while (cur) {
            swap(cur->next, prev);
            swap(prev, cur);
        }

        return prev;
    }
};