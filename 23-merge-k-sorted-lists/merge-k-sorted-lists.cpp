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
    bool static comp(ListNode* a,ListNode* b)
    {
        return a->val>b->val;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,decltype(&comp)> minHeap(comp);
        for (ListNode* list:lists)
        {
            if (list!=nullptr)
                minHeap.push(list);
        }
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while (!minHeap.empty())
        {
            ListNode* top=minHeap.top();
            minHeap.pop();
            tail->next=top;
            tail=top;
            if (top->next!=nullptr)
                minHeap.push(top->next);
        }
        ListNode* ans= dummy->next;
        delete dummy;
        return ans;
    }
};