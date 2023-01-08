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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        
        ListNode *curr=new ListNode(-1);
        ListNode *tail=curr;
        
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val < list2->val)
            {
                ListNode *temp=new ListNode(list1->val);
                tail->next=temp;
                tail=temp;
                list1=list1->next;
            }
            else if(list1->val > list2->val)
            {
                ListNode *temp=new ListNode(list2->val);
                tail->next=temp;
                tail=temp;
                list2=list2->next;
            }
            else{
                ListNode *temp1=new ListNode(list1->val);
                tail->next=temp1;
                tail=temp1;
                
                ListNode *temp2=new ListNode(list2->val);
                tail->next=temp2;
                tail=temp2;
                
                list1=list1->next;
                list2=list2->next;
            }
        }
        
        while(list1 != NULL)
        {
            ListNode *temp=new ListNode(list1->val);
            tail->next=temp;
            tail=temp;
            list1=list1->next;
        }
        
        while(list2 != NULL)
        {
            ListNode *temp=new ListNode(list2->val);
            tail->next=temp;
            tail=temp;
            list2=list2->next;
        }
        return  curr->next;
    }
};