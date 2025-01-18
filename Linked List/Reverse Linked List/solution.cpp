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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* next=nullptr;

        while(curr!=nullptr){
            next=curr->next;    // point to the next node
            curr->next=prev;    // reverse curr_node to prev_node

            prev=curr;  // update pointer to curr_node
            curr=next;  // update pointer to next_node
        }
        
        return prev;
    }
};