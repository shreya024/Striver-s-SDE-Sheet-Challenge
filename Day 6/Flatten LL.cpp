#include <bits/stdc++.h> 

Node *mergeLinkedList(Node* l1,Node *l2){
    Node *temp=new Node(0);
    Node *res=temp;
    
    while(l1!=NULL && l2!=NULL){
        if(l1->data<l2->data){
            temp->child=l1;
            temp=temp->child;
            l1=l1->child;
            temp->next=NULL;
        }
        else{
            temp->child=l2;
            temp=temp->child;
            l2=l2->child;
            temp->next=NULL;
        }
    }
    
    if(l1!=NULL)
        temp->child=l1;
    else
        temp->child=l2;
    
    return res->child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head->next==NULL)
        return head;
    head->next=flattenLinkedList(head->next);
    Node *merged=mergeLinkedList(head,head->next);
    return head;
}
