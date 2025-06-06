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
    int lenLinkedList(ListNode* head)
    {
        int count=0;
        while (head!=NULL)
        {
            count++;
            head=head->next;
        }
        return count;
    }

    ListNode* middleNode(ListNode* head) {
        int len=lenLinkedList(head),count=0;
        ListNode* temp=head;
        while (count!=ceil(len/2))
        {
            count++;
            temp=temp->next;
        }
        return temp;
    }
};