#include <bits/stdc++.h> 

Node *firstNode(Node *head)
{
    if(head==NULL||head->next==NULL)
        return NULL;
    
	Node *slow=head;
    Node *fast=head;
    slow=slow->next;
    fast=fast->next->next;
    
    while(slow!=NULL && fast!=NULL){
        if(slow==fast){
           Node *dummy=head;
           while(slow!=dummy){
               slow=slow->next;
               dummy=dummy->next;
           }
           return slow;
        }
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL)
            fast=fast->next;
    }
    
    if(slow!=fast)
       return NULL;
    
}
