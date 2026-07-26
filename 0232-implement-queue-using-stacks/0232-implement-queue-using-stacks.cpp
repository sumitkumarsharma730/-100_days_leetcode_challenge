// Operation	    Your Code	Optimized
// push()	        O(n)	    O(1)
// pop()	        O(1)	    O(1) amortized
// peek()	        O(1)	    O(1) amortized
// empty()	        O(1)	    O(1)
// Extra Space	    O(n)	    O(n)

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    MyQueue() {}

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (empty())
            return -1;

        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        int value = st2.top();
        st2.pop();
        return value;
    }

    int peek() {
        if (empty())
            return -1;

        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};

// For n elements:

// Total work = O(n).
// Therefore, the average cost per operation is O(1) (amortized).