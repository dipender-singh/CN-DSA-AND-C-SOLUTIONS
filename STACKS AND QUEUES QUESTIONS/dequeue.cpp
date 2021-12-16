class Deque { 
    int arr[10];
    int front;
    int rear;
    int size;
    public :
        Deque(int size) {
            front = -1;
            rear = 0;
            this -> size = size;
        }
    //Checks whether deque is full or not.
    bool isFull() {
        // used % operator is insertion and deletion is in circular manner 
        return (front == (rear + 1) % size);
    }
    //Checks whether Deque is empty or not.
    bool isEmpty () {
        return (front == -1);
    }
    // Inserts an element at front 
    void insertFront(int input) {
        if (isFull()) {
            cout << "-1\n";
            return;
        }
        if (isEmpty()) {    //isEmpty() ?
            front = 0;
            rear = 0;
        }
        else {
            // used % operator is insertion is in circular manner
            front = ((front - 1) % size + size) % size;
        }
        arr[front] = input ;
    } 
    // function to inset element at rear end of Deque. 
    void insertRear(int input) {
        if (isFull()) { 
            cout << "-1\n ";
            return;
        }
        if (isEmpty()) { 
            front = 0;
            rear = 0;
        }
        else {
            // used % operator is insertion is in circular manner
            rear = (rear + 1) % size;
        }
        arr[rear] = input;
    }
    // Deletes element at front end of Deque
    void deleteFront() {
        if (isEmpty()) {
            cout << "-1\n";
            return ;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            // used % operator is deletion is in circular manner
            front = (front + 1) % size;
        }
    }
    // Delete element at rear end of Deque
    void deleteRear() { 
        if (isEmpty()) {
            cout << "-1\n";
            return ;
        }
        if (front == rear) { 
            front = -1;
            rear = -1; 
        }
        else {
            // used % operator is deletion is in circular manner
            rear = ((rear-1) % size + size) % size;
        }
    }
    // Returns front element of Deque 
    int getFront() {
        if (isEmpty()) { 
            return -1 ;
        }
        return arr[front];
    }
    // function return rear element of Deque 
    int getRear() {
        if(isEmpty()) {
            return -1 ;
        }
        return arr[rear];
    }
};
