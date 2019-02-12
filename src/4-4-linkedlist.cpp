#include<cstdio>
#include<cstdlib>
#include<cstring>

struct Node
{
    int key;
    Node *next, *prev;
};

class LinkedList {
public:
    Node *nil;

    LinkedList() {
        nil = new Node; 
        nil->next = nil;
        nil->prev = nil;
    }

    ~LinkedList() {
        delete nil;
    }

    void printList() {
        Node *cur = nil->next;
        bool isFirst = true;
        while(true) {
            if (cur == nil) {
                break;
            }
            if (!isFirst) {
                printf(" ");
            }
            printf("%d", cur->key);
            cur = cur->next;
            isFirst = false;
        }
        printf("\n");
    }

    void insert(int key) {
        Node *newnode = new Node;
        newnode->key = key;
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

    void deleteKey(int key) {
        deleteNode(findFirst(key));
    }

private: 
    Node* findFirst(int key) {
        Node *cur = nil->next;
        while (cur != nil && cur->key != key) {
            cur = cur->next;
        }
        return cur;
    }

    void deleteNode(Node *deleted) {
        if (deleted != nil) {
            deleted->prev->next = deleted->next;
            deleted->next->prev = deleted->prev;
            delete deleted;
        }
    }
};


int main() {
    int key, n, i;
    char command[20];
    scanf("%d", &n);
    
    auto* list = new LinkedList;
    for(i = 0; i < n; i++) {
        scanf("%s%d", command, &key);
        if (strcmp(command, "insert") == 0) {
            list->insert(key);
        } else if (strcmp(command, "delete") == 0) {
            list->deleteKey(key);
        } else if (strcmp(command, "deleteFirst") == 0) {
            list->deleteFirst();
        } else if (strcmp(command, "deleteLast") == 0) {
            list->deleteLast();
        }
    }

    list->printList();

    return 0;
}
