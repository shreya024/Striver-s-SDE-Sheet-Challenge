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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    
    LinkedListNode<int> *prev=NULL;
    LinkedListNode<int> *curr=head;
    
    while(curr!=NULL){
        LinkedListNode<int> *temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    
    head=prev;
    return head;
    
    
}
