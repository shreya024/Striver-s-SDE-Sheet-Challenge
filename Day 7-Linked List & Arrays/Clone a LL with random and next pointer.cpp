//Method 1---Using Hashmap-->T.C=O(N) & S.C=O(N)

#include <bits/stdc++.h> 

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    unordered_map<LinkedListNode<int> *,LinkedListNode<int> *> m;
    
    LinkedListNode<int> *temp=head;
    
    while(temp!=NULL){
        LinkedListNode<int> *newNode=new LinkedListNode<int>(temp->data);
        m[temp]=newNode;
        temp=temp->next;
    }
    
    temp=head;
    while(temp!=NULL){
        LinkedListNode<int> *newNode=m[temp];
        newNode->next=m[temp->next];
        newNode->random=m[temp->random];
        temp=temp->next;
    }
    
    return m[head];
}
