class MyCircularQueue {

private: 
    vector<int> rb;

    int tail = 0;
    int head = 0;
    int size = 0;

    int capacity;
        //a,b,c,d,e,f,s
public:
    MyCircularQueue(int k) 
    {
        rb.resize(k); // size =0, no elements, capacity for vector =k;
        capacity = k;
    }
    
    bool enQueue(int value) 
    {
        if(isFull()) return false;

        rb[tail] = value;
        tail = (tail + 1) % capacity;
        size += 1;
        return true;
    }
    
    bool deQueue() 
    {
        if(isEmpty()) return false;
  
        head = (head + 1) % capacity; // deque with position and not erasing - zero copy
        size -= 1;
        return true;

    }
    
    int Front() 
    {
        if(isEmpty()) return -1;

        return rb[head];
    }
    
    int Rear() {
         if(isEmpty()) return -1;
        int idx = (tail - 1 + capacity) % capacity; //prev tail in case of tail = 0, we need to wrap it
        return rb[idx];
    }
    
    bool isEmpty() {
        if(size <= 0) return true;
        return false;
    }
    
    bool isFull() 
    {
        if(size >= capacity) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */