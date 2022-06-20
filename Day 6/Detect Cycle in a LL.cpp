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
