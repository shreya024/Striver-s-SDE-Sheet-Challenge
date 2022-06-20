//Method 1---Hashing -> T.C=O(N) & S.C=O(N)

bool detectCycle(Node *head)
{
	unordered_set<Node *> s;
    while(head!=NULL){
        if(s.find(head)!=s.end()){
            return true;
        }
        else{
            s.insert(head);
            head=head->next;
        }
    }
    
    return false;
}


//Method 2---Slow and Fast Pointer -> T.C=O(N) & S.C=O(1)

bool detectCycle(Node *head)
{
	Node *slow=head;
    Node *fast=head->next;
    
    while(slow!=NULL && fast!=NULL){
        if(slow==fast)
            return true;
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL)
            fast=fast->next;
    }
    
    return false;
}
