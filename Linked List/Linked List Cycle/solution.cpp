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
        if(head==nullptr)
            return false;
            
        ListNode* fast=head;
        ListNode* slow=head;
        bool ans=false;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ans=true;
                break;
            }
        }

        return ans;
    }
};