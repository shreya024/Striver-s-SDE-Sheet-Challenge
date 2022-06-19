#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/
int findLength(Node *head){
    Node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
Node *findMiddle(Node *head) {
    if(head==NULL||head->next==NULL)
        return head;
    int length=findLength(head);
    Node * temp=head;
    length=length/2;
    for(int i=1;i<=length;i++){
        temp=temp->next;
    }
    return temp;
}
