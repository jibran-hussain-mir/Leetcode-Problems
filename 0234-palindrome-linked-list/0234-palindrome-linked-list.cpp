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
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
        {
            return true;
        }
        
//     Copy the elements of linked list in vector
        vector<int> v;
        while(head != NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        
//     Size of an array
        int len=v.size();
        
        int s=0,e=len-1;
        
        while(s < e)
        {
            if(v[s] == v[e])
            {
                s++;
                e--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};