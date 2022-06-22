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


//Method 2---By creating copies in between the originals-->T.C=O(N) & S.C=O(1)

#include <bits/stdc++.h> 

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    
    LinkedListNode<int> *temp=head;
    
    //Step 1: Insert copy nodes in between the original nodes
    while(temp!=NULL){
        LinkedListNode<int> *newNode=new LinkedListNode<int>(temp->data);
        newNode->next=temp->next;
        temp->next=newNode;
        temp=newNode->next;
    }
    
    temp=head;
    //Step 2:Assigning the random pointers
    while(temp!=NULL){
        if(temp->random==NULL)
            temp->next->random=NULL;
        else
            temp->next->random=temp->random->next;
        temp=temp->next->next;
    }
    
    //Step 3: Separate the copy LL and the original LL
    temp=head;
    LinkedListNode<int> *dummy=new LinkedListNode<int>(0);
    LinkedListNode<int> *res=dummy;
    
    while(temp!=NULL){
        LinkedListNode<int> *front=temp->next->next;
        dummy->next=temp->next;
        temp->next=front;
        temp=front;
        dummy=dummy->next;
    }
    
    return res->next;
}
