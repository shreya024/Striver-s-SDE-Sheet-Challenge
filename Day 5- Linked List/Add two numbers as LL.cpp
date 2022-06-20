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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    
    int carry=0,sum=0;
    Node *head=new Node(-1);
    Node *curr=head;
    
    while(head1!=NULL && head2!=NULL){
        sum=head1->data + head2->data+carry;
        Node* temp=new Node(sum%10);
        carry=sum/10;
        curr->next=temp;
        curr=curr->next;
        head1=head1->next;
        head2=head2->next;
    }
    
    while(head1!=NULL ){
        sum=head1->data+carry;
        Node* temp=new Node(sum%10);
        carry=sum/10;
        curr->next=temp;
        curr=curr->next;
        head1=head1->next;
    }
    
    while(head2!=NULL){
        sum= head2->data+carry;
        Node* temp=new Node(sum%10);
        carry=sum/10;
        curr->next=temp;
        curr=curr->next;
        head2=head2->next;
    }
    while(carry!=0){
        Node* temp=new Node(carry);
        carry=carry/10;
        curr->next=temp;
        curr=curr->next;
    }
    
    return head->next;
}
