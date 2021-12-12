#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<memory>
using namespace std;

template <class T>
struct Node
{
    T value;
    Node<T> *next, *prev;
};

template <class T>
class LinkedList {
public:
    Node<T> *nil;

    LinkedList() {
        nil = new Node<T>; 
        nil->next = nil;
        nil->prev = nil;
    }

    ~LinkedList() {
        delete nil;
    }

    void printList() {
        Node<T> *cur = nil->next;
        bool isFirst = true;
        while(true) {
            if (cur == nil) {
                break;
            }
            if (!isFirst) {
                printf(" ");
            }
            printf("%d", cur->value);
            cur = cur->next;
            isFirst = false;
        }
        printf("\n");
    }

    void insert(T value) {
        Node<T> *newnode = new Node<T>;
        newnode->value = value;
        newnode->next = nil->next;
        nil->next->prev = newnode;
        nil->next = newnode;
        newnode->prev = nil;
    }

    void deleteFirst() {
        deleteNode(nil->next);
    }

    void deleteLast() {
        deleteNode(nil->prev);
    }

    void deleteKey(T value) {
        deleteNode(findFirst(value));
    }

private: 
    Node<T>* findFirst(T value) {
        Node<T> *cur = nil->next;
        while (cur != nil && cur->value != value) {
            cur = cur->next;
        }
        return cur;
    }

    void deleteNode(Node<T> *deleted) {
        if (deleted != nil) {
            deleted->prev->next = deleted->next;
            deleted->next->prev = deleted->prev;
            delete deleted;
        }
    }
};


int main() {
    int value, n, i;
    char command[20];
    scanf("%d", &n);
    
    unique_ptr<LinkedList<int>> list(new LinkedList<int>);
    for(i = 0; i < n; i++) {
        scanf("%s%d", command, &value);
        if (strcmp(command, "insert") == 0) {
            list->insert(value);
        } else if (strcmp(command, "delete") == 0) {
            list->deleteKey(value);
        } else if (strcmp(command, "deleteFirst") == 0) {
            list->deleteFirst();
        } else if (strcmp(command, "deleteLast") == 0) {
            list->deleteLast();
        }
    }

    list->printList();
}
