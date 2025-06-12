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
    int getDecimalValue(ListNode* head) {
        int val=0,len=0;
        ListNode* temp=head;
        while (temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        int twos=1;
        for (int i=0;i<len-1;i++)
            twos*=2;
        temp=head;
        while (temp!=NULL)
        {
            val+=twos*temp->val;
            twos/=2;
            temp=temp->next;
        }
        return val;
        
    }
};