#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(head==NULL ||K==0)
        return head;
    
    int n=0;
    LinkedListNode<int> *curr=head;
    LinkedListNode<int> *prev=NULL;
    
    while(curr!=NULL){
        n++;
        curr=curr->next;
    }
    
    curr=head;
    K=n-K;
    while(K>0){
        prev=curr;
        curr=curr->next;
        K--;
    }
    if(prev!=NULL){
        prev->next=curr->next;
    }
    else{
        head=head->next;
    }
    
    return head;
}
