#include<stdio.h>
#include<stdlib.h>
#include<string.h>

template <typename T>
class Stack {
public:
    int top_idx;
    T S[1000];

    Stack() {
        top_idx = 0;
    }

    void push(T x) {
        S[++top_idx] = x;
    }

    T pop() {
        top_idx--;
        return S[top_idx+1];
    }
};

int main() {
    int a, b;
    Stack<int>* stack = new Stack<int>;
    char s[100];

    while( scanf("%s", s) != EOF) {
        if (s[0] == '+') {
            a = stack->pop();
            b = stack->pop();
            stack->push(a + b);
        } else if (s[0] == '-') {
            b = stack->pop();
            a = stack->pop();
            stack->push(a - b);
        } else if (s[0] == '*') {
            a = stack->pop();
            b = stack->pop();
            stack->push(a * b);
        } else {
            stack->push(atoi(s));
        }
    }

    printf("%d\n", stack->pop());

    return 0;
}
