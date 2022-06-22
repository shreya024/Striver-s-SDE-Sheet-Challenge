#include <bits/stdc++.h> 

int getLength(Node* head){
    Node *temp=head;
    
    int n=0;
    while(temp!=NULL){
        n++;
        temp=temp->next;
    }
    return n;
}

pair<Node*,Node*> getNodes(Node* head,int k,int n){
    Node *temp=head;
    pair<Node*,Node*> nodes;
    
    for(int i=1;i<=n-k-1;i++){
        temp=temp->next;
    }
    nodes.first=temp->next;
    temp->next=NULL;
    temp=nodes.first;
    while(temp->next!=NULL)
        temp=temp->next;
    
    nodes.second=temp;
    
    return nodes;
}

Node *rotate(Node *head, int k) {
    int n=getLength(head);
       if(k>=n){
            k=k%n;
        }
     
    if(k==0||head==NULL||head->next==NULL)
        return head;
     pair<Node*,Node*> nodes=getNodes(head,k,n);
    
    nodes.second->next=head;
    return nodes.first;
}
