#include <iostream>
#include <memory>
using namespace std;


class PostorderReconstructor {

public:
    int *preIds;
    int *inIds;
    int *postIds;
    int count;
    int currentPrePos = 0;
    int currentPostPos = 0;

    PostorderReconstructor(int preorderIds[], int inorderIds[], int cnt) {
        preIds = preorderIds;
        inIds = inorderIds;
        count = cnt;
        postIds = (int *)malloc(sizeof(int) * cnt);
    }

    ~PostorderReconstructor() {
        free(postIds);
    }

    void reconstruct(int leftPos, int rightPos) {
        if (leftPos >= rightPos)
            return;

        auto nextRoot = preIds[currentPrePos];
        currentPrePos += 1;
        auto middlePos = findInorderPos(nextRoot);

        reconstruct(leftPos, middlePos);
        reconstruct(middlePos + 1, rightPos);

        postIds[currentPostPos] = nextRoot;
        currentPostPos += 1;
    }

private:
    
    int findInorderPos(int id) {
        for (int i = 0; i < count; i++)
        {
            if (inIds[i] == id)
                return i;
        }
        throw "can`t find index in inorder ids";
    }
};


int main() {
    int N, i;

    cin >> N;

    int preorderIds[N], inorderIds[N];

    for (i = 0; i < N; i++)
    {
        cin >> preorderIds[i];
    }

    for (i = 0; i < N; i++)
    {
        cin >> inorderIds[i];
    }

    unique_ptr<PostorderReconstructor> reconstructor(new PostorderReconstructor(preorderIds, inorderIds, N));

    reconstructor->reconstruct(0, N);

    for (i = 0; i < N; i++)
    {
        if (i > 0)
            cout << " ";

        cout << reconstructor->postIds[i];
    }
    
    cout << endl;

}
