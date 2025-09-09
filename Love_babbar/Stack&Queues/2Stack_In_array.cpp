#include <bits/stdc++.h>
using namespace std;

class TwoStack {
public:
    vector<int> st;
    int top1;
    int top2;
    int size;

    // Initialize TwoStack.
    TwoStack(int s) {
        st = vector<int>(s);
        size = s;
        top1 = -1;     // stack1 empty
        top2 = s;      // stack2 empty
    }
    
    // Push in stack 1.
    void push1(int num) {
        if (top1 + 1 < top2) {   // only if space available
            st[++top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if (top1 + 1 < top2) {   // only if space available
            st[--top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if (top1 >= 0) {
            return st[top1--];
        }
        return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 < size) {
            return st[top2++];
        }
        return -1;
    }
};
