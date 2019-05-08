#include<iostream>
#include<memory>
using namespace std;

typedef long long llong;


class MinimumCapacitySolver {

public:
    static const int MAX = 100000;

    MinimumCapacitySolver (int cCnt, int tCnt, llong weights[]) {
        for (int i = 0; i < cCnt; i++) {
            cargoWeights[i] = weights[i];
        }
        cargoCnt = cCnt;
        trackCnt = tCnt;
    }

    int check(llong trackCapacity) {
        auto i = 0;
        for (int j = 0; j < trackCnt; j++) {
            llong s = 0;
            while(s + cargoWeights[i] <= trackCapacity) {
               s += cargoWeights[i];
               i++;
               if (i == cargoCnt) {
                   return cargoCnt;
               }
            }
        }
        return i;
    }

    int solve() {
        llong left = 0;
        llong right = MAX * 10000;
        llong mid;

        while(right - left > 1) {
            mid = (left + right) / 2;
            auto v = check(mid);
        
            if (v >= cargoCnt) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return right;
    }

private: 
    llong cargoWeights[MAX];
    int cargoCnt;
    int trackCnt;
};


int main() {
    int cargoCnt, trackCnt;
    llong cargoWeights[MinimumCapacitySolver::MAX];
    cin >> cargoCnt >> trackCnt;

    for (int i = 0; i < cargoCnt; i++) {
        cin >> cargoWeights[i];
    }   
    unique_ptr<MinimumCapacitySolver> solver(new MinimumCapacitySolver(cargoCnt, trackCnt, cargoWeights));

    llong ans = solver->solve();
    cout << ans << endl;
}
