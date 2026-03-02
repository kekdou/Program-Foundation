#include <iostream>
#include<vector>

using namespace std;

int main() {
    int n, T;
    cin >> n >> T;
    vector<int> V(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        int v = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                v += V[i];
            }
        }
        if (v == T) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}