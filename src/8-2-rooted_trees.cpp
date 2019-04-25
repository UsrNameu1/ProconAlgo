#include <iostream>
using namespace std;

static const int MAX_N = 100000;


struct Node {
    int id;
    int degree;
    int child_ids[];
};

int main() {
    int N;
    int id;
    int degree;
    int i, j, k;

    cin >> N;

    Node nodes[N];

    for (i = 0; i < N; i++)
    {
        cin >> nodes[i].id >> nodes[i].degree;
        for (j = 0; j < nodes[i].degree; j++)
        {
            cin >> nodes[i].child_ids[j];
        }
    }

    for (i = 0; i < N; i++) {
        int parent = -1;
        int depth = 0;
        string type;

        // finding parent
        for (j = 0; j < N; j++)
        {
            bool found = false;
            if (j != i)
            {
                for (k = 0; k < nodes[j].degree; k++) {
                    if (nodes[i].id == nodes[j].child_ids[k]) {
                        parent = nodes[j].id;
                        found = true;
                        break;
                    }
                }
            }

            if (found)
                break;
        }

        // finding depth
        cout << "node " << nodes[i].id << ": parent = " << parent << endl;
    }

    return 0;
}
