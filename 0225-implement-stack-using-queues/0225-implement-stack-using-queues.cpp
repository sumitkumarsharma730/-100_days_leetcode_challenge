class MyStack {
public:
    static const int Max = 100;
    int *arr;
    int capacity = -1;
    MyStack() {
        arr = new int[Max];
        cout << "null" << endl;
    }
    
    void push(int x) {
        if(capacity == Max-1){
            cout << "Overflow" << endl;
        }
        else{
            capacity++;
            arr[capacity] = x;
            cout << "null" << endl;
        }
    }
    
    int pop() {
        if(capacity == -1){
            return -1;
        }
        int value = arr[capacity];
        capacity--;
        return value;
    }
    
    int top() {
        if(capacity == -1){
            return -1;
        }
        return arr[capacity];
    }
    
    bool empty() {
        if(capacity == -1) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */