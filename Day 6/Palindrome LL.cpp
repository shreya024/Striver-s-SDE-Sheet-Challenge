#include <bits/stdc++.h> 
LinkedListNode<int> *getMid(LinkedListNode<int> *head){
    LinkedListNode<int> *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    temp=head;
    count/=2;
    while(count--){
        temp=temp->next;
    }
    return temp;
}
LinkedListNode<int> *reverseList(LinkedListNode<int> *head){
    LinkedListNode<int> *prev=NULL;
    LinkedListNode<int> *curr=head;
    
    while(curr!=NULL){
        LinkedListNode<int> *temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL ||head->next==NULL)
        return true;
    LinkedListNode<int> *first=head;
    LinkedListNode<int> *mid=getMid(head);
    LinkedListNode<int> *second=reverseList(mid);
    
    while(second!=NULL){
        if(first->data!=second->data)
            return false;
        first=first->next;
        second=second->next;
    }
    return true;
}
