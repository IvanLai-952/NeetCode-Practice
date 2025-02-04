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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int target=getSize(head)-n;
        ListNode* ptr=head;
        ListNode* prev=nullptr;

        if(target==0)
            return head->next;

        while(target!=0){
            target--;
            prev=ptr;
            ptr=ptr->next;
        }
        prev->next=ptr->next;

        return head;
    }
private:
    int getSize(ListNode* head){
        ListNode* ptr=head;
        int length=0;

        while(ptr){
            length++;
            ptr=ptr->next;
        }

        return length;
    }
};