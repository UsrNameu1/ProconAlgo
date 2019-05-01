#include <iostream>
using namespace std;


struct Node {
    int id;
    int parentId;
    int leftId;
    int rightId;
};


class BinaryTree {

public:
    static const int NIL_ID = -1;
    Node *nodes;

    BinaryTree(int cnt) {
        nodes = (Node *)malloc(sizeof(Node) * cnt);
        for (int i = 0; i < cnt; i++)
        {
            nodes[i] = Node{i, NIL_ID, NIL_ID, NIL_ID};
        }
    }

    ~BinaryTree() {
        delete nodes;
    }

    void push_values(int id, int leftId, int rightId) {
        nodes[id].leftId = leftId;
        nodes[id].rightId = rightId;

        if (leftId != NIL_ID)
            nodes[leftId].parentId = id;
        if (rightId != NIL_ID)
            nodes[rightId].parentId = id;
    }

    int getSibling(int id) {
        Node node = nodes[id];

        int parentId = node.parentId;
        if (parentId == NIL_ID)
            return NIL_ID;
        
        Node parent = nodes[parentId];

        if (parent.leftId == id) {
            return parent.rightId;
        } else {
            return parent.leftId;
        }    
    }

    int getDegree(int id) {
        Node node = nodes[id];

        int degree = 0;
        
        if (node.leftId != NIL_ID)
            degree++;
        if (node.rightId != NIL_ID)
            degree++;

        return degree;
    }

    int getDepth(int id) {
        Node node = nodes[id];
        int depth = 0;

        while(node.parentId != NIL_ID) {
            node = nodes[node.parentId];
            depth++;
        }

        return depth;
    }

    int getHeight(int id) {
        int h1 = 0, h2 = 0;
        Node node = nodes[id];

        if (node.rightId != NIL_ID)
            h1 = getHeight(node.rightId) + 1;
        if (node.leftId != NIL_ID)
            h2 = getHeight(node.leftId) + 1;

        return max(h1, h2);
    }

    string getType(int id) {
        Node node = nodes[id];

        if (node.parentId == NIL_ID)
            return "root";
        
        if (getDegree(id) > 0) {
            return "internal node";
        } else {
            return "leaf";
        }
    }

    void printNode(int id) {
        Node node = nodes[id];
        cout << "node " << id << ": parent = " << node.parentId << ", sibling = ";
        cout << getSibling(id) << ", degree = " << getDegree(id) << ", depth = ";
        cout << getDepth(id) << ", height = " << getHeight(id) << ", " << getType(id);
    }
};


int main() {
    int N;
    int i, id, leftId, rightId;

    cin >> N;

    BinaryTree tree = BinaryTree(N);

    for (i = 0; i < N; i++) {
        cin >> id >> leftId >> rightId;
        tree.push_values(id, leftId, rightId);
    }

    for (i = 0; i < N; i++) {
        tree.printNode(i);
        cout << endl;
    }

    return 0;
}
