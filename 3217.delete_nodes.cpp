/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        while (prev->next != nullptr) {
            ListNode* currentNode = prev->next;
            if (numsSet.count(currentNode->val)) {
                prev->next = currentNode->next;
                
            } else {
                prev = prev->next;
            }
        }
        return dummy.next;
    }
};