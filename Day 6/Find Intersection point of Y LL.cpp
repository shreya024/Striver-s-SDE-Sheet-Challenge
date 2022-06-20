//Method 1---T.L.E ->O(N^2)

int findIntersection(Node *firstHead, Node *secondHead)
{
    Node *temp=firstHead;
    while(secondHead!=NULL){
        while(temp!=NULL){
            if(temp==secondHead)
                return temp->data;
            temp=temp->next;
        }
        temp=firstHead;
        secondHead=secondHead->next;
    }
    
    return -1;
}
