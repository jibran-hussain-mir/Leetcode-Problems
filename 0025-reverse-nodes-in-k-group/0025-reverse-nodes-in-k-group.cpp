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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        
        int checkCount=0;
        ListNode* temp=head;
        while(temp!=NULL){
            checkCount++;
            temp=temp->next;
        }
        
        if(checkCount < k) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        int count = 0;
        
        while(curr != NULL && count < k){
            forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        
        if(curr != NULL) head->next=reverseKGroup(curr,k);
        
        return prev;
    }
};