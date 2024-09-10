#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<int, set<int>> X_map, Y_map;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        X_map[x].insert(y);
        Y_map[y].insert(x);
    }

    int result = 0;
    for (const auto& x : X_map) {
        if (x.second.size() > 1)
            result++;
        cout << "x first : " << x.first << " / x second size : " << x.second.size()  << "\n"; 
    }
    for (const auto& y : Y_map) {
        if (y.second.size() > 1)
            result++;
        cout << "y first : " << y.first << " / y second size : " << y.second.size()  << "\n"; 
    }

    cout << result << "\n";

    return 0;
}