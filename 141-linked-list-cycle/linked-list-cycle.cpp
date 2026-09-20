class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> mp;

        while (head) {
            if (mp.count(head))
                return true;

            mp[head]++;
            head = head->next;
        }

        return false;
    }
};