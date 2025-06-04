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
        int len=0;
        ListNode* temp=head;
        if (head==nullptr) return head;
        while (temp!=NULL)
        {
            temp=temp->next;
            len++;
        }
        if (n==len)
        {
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }

        temp=head;
        int count=1;
        while (count!=len-n)
        {
            count++;
            temp=temp->next;
        }

        ListNode* temp1=temp->next;
        temp->next=temp->next->next;
        delete temp1;
        return head;
    }
};