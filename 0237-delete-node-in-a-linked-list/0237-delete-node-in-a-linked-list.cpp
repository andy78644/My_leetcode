/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        auto tmp = node->next;
        *node = *node->next;
        delete tmp;
        tmp = nullptr;
    }
};

//1 2 3 4 5 6
//1 2 4 4 5 6