#include<iostream>
using namespace std;

int bubbleSort(int A[], int N) {
    int sw = 0;
    bool flag = true;
    for(int i = 0; flag; i++)
    {
        flag = false;
        for(int j = N -1; j >= i + 1; j--)
        {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = true;
                sw++;
            }
        }
    }
    return sw;
}

int main() {
    int A[100], N, sw;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    
    sw = bubbleSort(A, N);

    for(int i = 0; i < N; i++)
    {
        if (i > 0) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;

    return 0;
}
