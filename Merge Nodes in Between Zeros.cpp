class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curNode = head->next;
        ListNode* lastNode = head;

        int sum = 0;
        while (curNode) {
            if (curNode->val != 0) {
                sum += curNode->val;
            } else {
                lastNode->val = sum;
                if(curNode->next) lastNode = lastNode->next;
                sum = 0;
            }
            curNode = curNode->next;
        }
        lastNode->next = nullptr;
        return head;
    }
};
------------------------------------------------------------------
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curNode = head->next;
        ListNode* lastNode = curNode;

        while (curNode) {
            int sum = 0;
            while(curNode->val != 0){
                sum+= curNode->val;
                curNode = curNode->next;
            }
            lastNode->val = sum;
            curNode = curNode->next;
            lastNode->next = curNode;
            lastNode = lastNode->next;
        }
        return head->next;
    }
};
