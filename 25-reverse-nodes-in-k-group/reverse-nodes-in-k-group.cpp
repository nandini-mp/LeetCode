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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k==1) return head;
        //count total number of nodes
        ListNode* temp=head;
        int count=0;
        while (temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        ListNode* dummy = new ListNode();
        dummy->next=head;
        ListNode* prevGroupEnd=dummy; //tracks the end of the previously reverseed group, so we can reconnect the reversed segments
        while (count>=k)
        {
            ListNode* curr=prevGroupEnd->next; //first node in the current group, it is the current node being held in-place
            ListNode* nextNode=curr->next; //node after curr
            for (int i=1;i<k;i++) //k-1 swaps
            {//move next to the front of every group
                curr->next=nextNode->next; //curr now points to what comes afer nextNode
                nextNode->next=prevGroupEnd->next; //point nextNode to the front of the group (initially curr)
                prevGroupEnd->next=nextNode; //move nextNode to the front of the group
                nextNode=curr->next; //advance nextNode to the next node to be moved
            }
            prevGroupEnd=curr; //curr becomes the new group's end after reversal
            count-=k;
        }
        return dummy->next;
    }   
};