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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode* temp1=head;
        int count=0;
        while (temp1!=NULL)
        {
            count++;
            temp1=temp1->next;
        }
        k=k%count;
        for (int i=0;i<k;i++)
        {
            ListNode* temp=head;
            ListNode* prev=NULL;
            while (temp->next!=NULL)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            temp->next=head;
            head=temp;
        }
        return head;
    }
};