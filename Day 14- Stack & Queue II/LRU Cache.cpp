#include <unordered_map>

class Node{
    public:
        int key;
        int val;
        Node *prev;
        Node *next;
    
    Node(int k,int v){
        key=k;
        val=v;
    }
};

class LRUCache
{
public:
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    
    int cap;
    unordered_map<int,Node*> m;
    
    LRUCache(int capacity)
    {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(Node *newNode){
        Node *temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    
    void deleteNode(Node *delNode){
        Node *delprev=delNode->prev;
        Node *delnext=delNode->next;
        delprev->next=delnext;
        delnext->prev=delprev; 
    }

    int get(int key)
    {
        // key found
        if(m.find(key)!=m.end()){
            Node *resnode=m[key];
            int res=resnode->val;
            m.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            m[key]=head->next;
            return res;
        }
        //key not found
        return -1;
    }

    void put(int key, int value)
    {
        // key in Cache
        if(m.find(key)!=m.end()){
            Node *existingNode=m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        
        //Capacity is reached
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new Node(key,value));
        m[key]=head->next;
    }
};
