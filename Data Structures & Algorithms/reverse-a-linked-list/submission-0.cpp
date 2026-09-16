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
    ListNode* reverseList(ListNode* head) {
        ListNode* tail;
        ListNode* prev = nullptr;
        ListNode* temp;
        if(head == nullptr){
            return nullptr;
        }
        while(head != nullptr){
            temp = head ->next;
            tail = head;
            tail->next = prev;
            prev = tail;
            head = temp;

        }
        return tail;
    }
};
