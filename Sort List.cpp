class Solution {
public:
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode* ptr = new ListNode(0);
        ListNode* curr = ptr;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1 != nullptr) curr->next = l1;
        if (l2 != nullptr) curr->next = l2;

        return ptr->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = head;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        return mergeList(sortList(head), sortList(slow));
    }
};
