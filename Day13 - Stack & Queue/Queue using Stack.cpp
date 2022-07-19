#include <stack>

class Queue {
    stack<int> input,output;
    
    public:
    Queue() {
       
    }

    void enQueue(int val) {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        
        input.push(val);
        
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }

    int deQueue() {
        if(input.empty())
            return -1;
        int n=input.top();
        input.pop();
        return n;
    }

    int peek() {
        if(input.empty())
            return -1;
        return input.top();
    }

    bool isEmpty() {
        return input.empty();
    }
};
