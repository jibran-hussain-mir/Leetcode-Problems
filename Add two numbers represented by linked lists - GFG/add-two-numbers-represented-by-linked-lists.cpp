//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    // Funciton to reverse linked list
    struct Node* reverse(struct Node* &head)
        {
            Node* curr=head;
            Node* prev=NULL;
            Node* forward=NULL;
            
            while(curr != NULL)
                {
                    forward=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=forward;
                }
            return prev;
        }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node *newFirst=reverse(first);
        Node *newSecond=reverse(second); 
        
        Node* curr1=newFirst;
        Node* curr2=newSecond;
        
        int carry=0;
        Node* resHead=new Node(-1);
        Node* tail=resHead;
        while(curr1 != NULL && curr2 != NULL)
            {
              int val=curr1->data+curr2->data+carry;
              int ans=val%10;
              carry=val/10;
              Node* temp=new Node(ans); 
              tail->next=temp;
              tail=temp;
              curr1=curr1->next;
              curr2=curr2->next;
            }
        while(curr1 != NULL)
            {
             int val=curr1->data+ carry;
             int ans=val % 10;
             carry=val/10;
             Node* temp=new Node(ans);  
             tail->next=temp;
             tail=temp;
             curr1=curr1->next;
            }
      while(curr2 != NULL)
            {
             int val=curr2->data+ carry;
             int ans=val % 10;
             carry=val/10;
             Node* temp=new Node(ans);  
             tail->next=temp;
             tail=temp;
             curr2=curr2->next;
            }
        if(carry)
            {
                Node* temp=new Node(carry);
                tail->next=temp;
                tail=temp;
            }
            
        return reverse(resHead->next);
    }
    
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends