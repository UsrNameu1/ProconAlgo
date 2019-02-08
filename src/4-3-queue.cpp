#include<stdio.h>
#include<string.h>
#include<algorithm>
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

    Queue(int n) {
        head = 1;
        tail = n + 1;
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
    int i, q, n;
    Process u;
    scanf("%d %d", &n, &q);

    auto* queue = new Queue<Process>(n);
    for( i = 1; i <= n; i++)
    {
        scanf("%s", queue->storage[i].name);
        scanf("%d", &(queue->storage[i].t));
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

    return 0;
}
