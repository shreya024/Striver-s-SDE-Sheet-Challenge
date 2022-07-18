#include<queue>

class Stack {
	// Define the data members.
    queue<int> q;
    int siz;
   public:
    Stack() {
        siz=-1;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return (q.empty());
    }

    void push(int element) {
        
        siz++;
        q.push(element);
        for(int i=0;i<siz;i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(q.empty())
            return -1;
        int n=q.front();
        q.pop();
        siz--;
        return n;
        
    }

    int top() {
        if(q.empty())
            return -1;
        int n=q.front();
        return n;
    }
};
