#include<iostream>
#include<algorithm>
using namespace std;

static const int MAX_N = 1000;
static const u_short MAX_ELEM = 10000;

int costToSort(u_short In[], u_short Sorted[], u_short size) {
    int i;
    bool visited[size];
    int cost = 0;
    u_short all_min = *min_element(In, In + size);

    for (i = 0; i < size; i++)
    {
        visited[i] = false;
    }

    for (i = 0; i < size; i++)
    {
        auto elem = In[i];
        auto cycle_min = elem;
        int cycle_sum = elem;
        u_short cycle_size = 1;
        auto cycle_idx = i;

        if (visited[cycle_idx])
            continue;

        while(true) {      
            visited[cycle_idx] = true;
            cycle_idx = lower_bound(Sorted, Sorted + size, elem) - Sorted;

            if (visited[cycle_idx])
                break;

            elem = In[cycle_idx];
            cycle_min = min(cycle_min, elem);
            cycle_sum += elem;
            cycle_size += 1;
        }

        cost += cycle_sum + min((cycle_size - 2) * cycle_min, cycle_min + (cycle_size + 1) * all_min);
    }

    return cost;
}

int main() {
    int N;

    cin >> N;

    u_short A[N];
    u_short B[N];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        B[i] = A[i];
    }

    sort(B, B + N);

    auto cost = costToSort(A, B, N);

    cout << cost;
    cout << endl;

    return 0;
}
