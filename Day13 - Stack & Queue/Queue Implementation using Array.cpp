class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() {
        size=100001;
        arr=new int[size];
        qfront=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront==rear)
            return true;
        return false;
    }

    void enqueue(int data) {
        if(rear==size)
            return;
        arr[rear]=data;
        rear++;
    }

    int dequeue() {
        if(isEmpty())
            return -1;
        int num=arr[qfront];
        arr[qfront]=-1;
        qfront++;
        if(qfront==rear){
            qfront=0;
            rear=0;
        }
        
        return num;
    }

    int front() {
        if(isEmpty())
            return -1;
        return arr[qfront];
    }
};
