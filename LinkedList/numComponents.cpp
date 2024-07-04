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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int> mpp;
        ListNode* temp = head;

        int numComponents = 0;
        
        for(int num:nums)
        {
            mpp[num]++;
        }

        while(temp!=NULL)
        {
            if(mpp.find(temp->val)!=mpp.end())
            {
                if(temp->next){
                    if(mpp.find(temp->next->val)==mpp.end()){
                        numComponents+=1;
                    }
                }
                else{
                    numComponents+=1;
                }
            }

            temp = temp->next;
        }
        
        return numComponents;
    }
};
