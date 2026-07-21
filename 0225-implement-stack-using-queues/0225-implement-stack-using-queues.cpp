// This sol. is wrong because question tells use Queues not array and linkedlist

class MyStack {
private:
    static const int MAX = 100;
    int arr[MAX];
    int topIndex;

public:
    MyStack() {
        topIndex = -1;
    }

    void push(int x) {
        arr[++topIndex] = x;
    }

    int pop() {
        return arr[topIndex--];
    }

    int top() {
        return arr[topIndex];
    }

    bool empty() {
        return topIndex == -1;
    }
};