#include<stdio.h>

bool solve (int A[], int len, int idx, int remain) {
    if (remain == 0) return true;
    if (idx >= len) return false;
    bool result = solve(A, len, idx + 1, remain) || solve(A, len, idx + 1, remain - A[idx]);
    return result;
}

int main() {
    int n, q, M, i;
    int A[50];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &M);
        if (solve(A, n, 0, M)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}
