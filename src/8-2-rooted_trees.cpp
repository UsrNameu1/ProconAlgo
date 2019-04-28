#include <iostream>
using namespace std;


struct Node {
    int id;
    int parentId;
    int leftChildId;
    int rightSiblingId;
};


class RootedTree {
public:
    static const int NIL_ID = -1;

    Node *nodes;
    int size;

    RootedTree(int n) {
        nodes = (Node *)malloc(sizeof(Node) * n);
        size = n;
        for (int i = 0; i < size; i++)
        {
            nodes[i] = Node{i, NIL_ID, NIL_ID, NIL_ID};
        }
    }

    ~RootedTree() {
        delete nodes;
    }

    void push_values(int id, int childCnt, int childIds[]) {
        int prevChildId = NIL_ID;
        for (int i = 0; i < childCnt; i++)
        {
            int childId = childIds[i];
            if (i == 0)
            {
                nodes[id].leftChildId = childId;
            } else {
                nodes[prevChildId].rightSiblingId = childId;
            }
            prevChildId = childId;
            nodes[childId].parentId = id;
        }
    }

    int getDepth(int id) {
        int d = 0;
        int curId = id;
        while (nodes[curId].parentId != NIL_ID)
        {
            curId = nodes[curId].parentId;
            d++;
        }
        return d;
    }

    void printNode(int id) {
        cout << "node " << id << ": parent = " << nodes[id].parentId << ", depth = ";
        int depth = getDepth(id);
        cout << depth << ", " << getNodeType(id, depth) << ", [";
        for (int i = 0, childId = nodes[id].leftChildId; childId != NIL_ID; childId = nodes[childId].rightSiblingId, i++)
        {
            if (i > 0)
                cout << ", ";
            cout << childId;
        }
        cout << "]";
    }

private:
    string getNodeType(int id, int depth) {
        if (depth == 0) {
            return "root";
        } else if (depth > 0 && nodes[id].leftChildId == NIL_ID) {
            return "leaf";
        } else if (depth > 0 && nodes[id].leftChildId != NIL_ID) {
            return "internal node";
        } else {
            throw "there is something wrong on input";
        }
    }
};


int main() {
    int N;
    int i, j, id, deg;

    cin >> N;

    RootedTree tree = RootedTree(N);

    for (i = 0; i < N; i++) {
        cin >> id >> deg;
        int childIds[deg];
        for (j = 0; j < deg; j++)
            cin >> childIds[j];
        tree.push_values(id, deg, childIds);
    }

    for (i = 0; i < N; i++) {
        tree.printNode(i);
        cout << endl;
    }

    return 0;
}
