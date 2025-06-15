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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodeSet;
        ListNode* temp=head;
        while (temp!=NULL)
        {
            if (nodeSet.count(temp)) return temp;
            nodeSet.insert(temp);
            temp=temp->next;
        }
        return NULL;
    }
};