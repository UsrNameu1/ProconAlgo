#include<stdio.h>

bool binarySearch(int A[], int n, int key) {
    auto left = 0;
    auto right = n;
    int mid;

    while(left < right){
        mid = (left + right) / 2;

        if (key == A[mid]) {
            return true;
        }
        if (key > A[mid]) {
            left = mid + 1;
        } else if (key < A[mid]) {
            right = mid;
        }
    }
    return false;
}

int main() {
    int i, q, k;
    int n;
    auto sum = 0;
    int A[1000000];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);

    for (i = 0; i < q; i++) {
        scanf("%d", &k);
        if (binarySearch(A, n, k)) {
            sum++;
        }
    }
    printf("%d\n", sum);
    
    return 0;
}
