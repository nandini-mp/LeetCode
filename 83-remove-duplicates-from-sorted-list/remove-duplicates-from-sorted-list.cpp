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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* temp=head;
        ListNode* tempNext=head->next;
        while (tempNext)
        {
            if (temp->val==tempNext->val)
            {
                ListNode* tempDel=tempNext;
                tempNext=tempNext->next;
                temp->next=tempNext;
                delete tempDel;
            }
            else
            {
                temp=tempNext;
                tempNext=tempNext->next;
            }
        }
        return head;
    }
};