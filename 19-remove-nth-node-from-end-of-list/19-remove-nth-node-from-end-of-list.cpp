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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return nullptr;
        ListNode *tmp = head;
        int count =1;
        while(tmp->next && tmp->next->next){
            tmp = tmp->next->next;
            count = count + 2;
        }
        if(tmp->next) count++;
        tmp = head;
        cout << count-n;
        if(count == n) return head->next;
        for(int i = 1;i<count-n;i++){
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return head;
    }
};