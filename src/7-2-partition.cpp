#include<iostream>
using namespace std;

static const int INFTY = 100000;
static const int MAX_N = 100000;
static int L[MAX_N / 2 + 2], R[MAX_N / 2 + 2];

int partition(int A[], int p, int r) {
    auto x = A[r];
    int i = p - 1;
    int j = 0;
    int tmp;
    
    for (j = p; j < r; j++) {
        if (A[j] <= x) {
            i += 1;
            tmp = A[j];
            A[j] = A[i];
            A[i] = tmp;
        }
    }  

    tmp = A[r];
    A[r] = A[i + 1];
    A[i + 1] = tmp;
    return i + 1; 
}

int main() {

    int A[MAX_N], N, i = 0;
    cin >> N;
    for(i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int idx = partition(A, 0, N - 1);

    for(i = 0; i < N; i++)
    {
        if (i > 0) {
            cout << " ";
        }

        if (i == idx) {
            cout << '[' << A[i] << ']';
        } else {
            cout << A[i];
        }
        
    }

    cout << endl;

    return 0;
}
