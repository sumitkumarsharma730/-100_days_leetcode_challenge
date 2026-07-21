// Complexity
// Operation	Time
// push	        O(n) ********************
// pop	        O(1)
// top	        O(1)
// empty	    O(1)
class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);

        int n = q.size();

        while (n > 1) {    // O(n)
            q.push(q.front()); 
            q.pop();
            n--;
        }
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};