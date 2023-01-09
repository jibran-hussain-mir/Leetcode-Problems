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
    
    ListNode* reverse(ListNode* &temp)
    {
        
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        while(temp != NULL)
        {
            forward=temp->next;
            temp->next=prev;
            prev=temp;
            temp=forward;
        }
        return prev;
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head->next == NULL) return true;
        
        ListNode *prev=NULL;
        ListNode *slow=head;
        ListNode *fast=head->next;
        
        while(fast != NULL && fast->next != NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* nextHead=reverse(slow->next);
        if(prev != NULL)            
            prev->next->next=nextHead;
        else slow->next=nextHead;
//         Comparing the two parts for palindrome
        
        ListNode* curr1=head;
        ListNode* curr2=nextHead;
        
        while(curr2 != NULL)
        {
            if(curr1->val != curr2->val)
                return false;
            curr2=curr2->next;
            curr1=curr1->next;
        }
        
        
        return true;
        
    }
};