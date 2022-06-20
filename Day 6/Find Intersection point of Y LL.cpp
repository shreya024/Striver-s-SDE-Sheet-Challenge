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


//Method 2---O(N) using Hashing

int findIntersection(Node *firstHead, Node *secondHead)
{
    unordered_set<Node*> s;
    
    while(firstHead!=NULL){
        s.insert(firstHead);
        firstHead=firstHead->next;
    }
    
    while(secondHead!=NULL){
        if(s.find(secondHead)!=s.end())
            return secondHead->data;
        secondHead=secondHead->next;
    }
    
    return -1;
}
