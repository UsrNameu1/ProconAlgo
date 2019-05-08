#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<memory>
using namespace std;

static const int LEN = 100005;

struct Process {
    char name[100];
    int t;
};

template <typename T>
class Queue {
public:
    T storage[LEN];
    int head, tail;

    Queue() {
        head = tail = 1;
    }

    void enqueue(T x) {
        storage[tail] = x;
        tail = (tail + 1) % LEN;
    }

    T dequeue() {
        T x = storage[head];
        head = (head + 1) % LEN;
        return x;
    }
};

int main() {
    int elaps = 0, c;
    int i, q, n, t;
    char name[100];
    Process u;
    scanf("%d %d", &n, &q);

    unique_ptr<Queue<Process>> queue(new Queue<Process>);
    for( i = 1; i <= n; i++)
    {
        Process *p = new Process;
        scanf("%s", p->name);
        scanf("%d", &(p->t));
        queue->enqueue(*p);
    }
    
    while( queue->head != queue->tail ) {
        u = queue->dequeue();
        c  = min(q, u.t);
        u.t -= c;
        elaps += c;
        
        if (u.t > 0) {
            queue->enqueue(u);
        } else {
            printf("%s %d\n", u.name, elaps);
        }
    }
}
