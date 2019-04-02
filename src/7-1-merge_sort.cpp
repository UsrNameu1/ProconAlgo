#include<iostream>
using namespace std;

static const int INFTY = 2000000000;
static const int MAX_N = 500000;
static int L[MAX_N / 2 + 2], R[MAX_N / 2 + 2];
static int cnt = 0;

void merge(int A[], int left, int mid, int right) {
    auto n1 = mid - left;
    auto n2 = right - mid;
    auto i = 0;

    for (i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }

    L[n1] = INFTY;
    R[n2] = INFTY;

    i = 0;
    auto j = 0;

    for (int k = left; k < right; k++) {
        cnt += 1;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i += 1;
        } else {
            A[k] = R[j];
            j += 1;
        }
    }
}

void mergeSort(int A[], int left, int right) {
    
    if  (left + 1 < right) {
        auto mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {

    int A[MAX_N], N, i = 0;
    cin >> N;
    for(i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    mergeSort(A, 0, N);

    for(i = 0; i < N; i++)
    {
        if (i > 0) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}
