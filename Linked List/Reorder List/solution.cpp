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

/* O(n) Solution */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }

        //if List length is even
        if(fast->next!=nullptr)
            slow=slow->next;
        
        slow=reverse(slow);

        // re-order
        ListNode* curr=head;
        ListNode* next=nullptr;

        while(curr!=nullptr && slow!=nullptr){
            next=curr->next;
            curr->next=slow;

            slow=slow->next;

            curr=curr->next;
            curr->next=next;
            curr=curr->next;
        }
        
        if(curr!=nullptr && curr->next!=nullptr)
            curr->next=nullptr;
        
    }
private:
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* next=nullptr;

        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;

            prev=curr;
            curr=next;
        }

        return prev;
    }
};

/* O(nlogn) Brute-Force Solution */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* ptr=head;

        while(ptr!=nullptr){
            ptr->next=(reverse(ptr->next));
            ptr=ptr->next;
        }
    }
private:
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* next=nullptr;

        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;

            prev=curr;
            curr=next;
        }

        return prev;
    }
};