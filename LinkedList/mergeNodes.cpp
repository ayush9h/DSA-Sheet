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
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;

        ListNode* start =head, *temp = head;
        int sum = 0;
        while(temp)
        {
            if(temp->val!=0)
            {
                sum+=temp->val;
            }
            else{
                start->val = sum;
                start->next = temp->next;
                start = temp->next;
                sum = 0;
            }
            temp=temp->next;
        }

        return head;
    }
};
