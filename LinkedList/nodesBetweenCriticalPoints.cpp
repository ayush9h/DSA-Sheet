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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL) return {-1,-1};

        vector<int> ans;

        ListNode* prev = head;
        ListNode* forw = head->next->next;
        int cnt = 1;
        while(forw!=NULL)
        {
            ListNode *curr = prev->next;

            if(curr->val > prev->val && curr->val > forw->val)
            {
                ans.push_back(cnt);
            }
            else if(curr->val < prev->val && curr->val < forw->val){
                ans.push_back(cnt);
            }
            cnt++;
            prev= prev->next;
            forw = forw->next;
        }

        if(ans.size() < 2)  return {-1,-1};
        int maxi;
        int mini = INT_MAX;
        for(int i = 1;i<ans.size();i++)
        {
            mini = min(mini, ans[i] - ans[i-1]);
        }

        maxi = ans[ans.size() - 1] - ans[0];

        return {mini,maxi};
    }
};
