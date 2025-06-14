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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> nodesSet;
        ListNode* temp=head;
        while (temp!=NULL)
        {
            if (nodesSet.count(temp)) return true;
            nodesSet.insert(temp);
            temp=temp->next;
        }
        return false;
    }
};