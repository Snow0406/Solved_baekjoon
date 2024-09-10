#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> list(N);
    unordered_set<int> able_number;
    long long cost = 0;
    
    for (int i = 1; i <= N; i++)
        able_number.insert(i);

    for (int i = 0; i < N; i++) {
        cin >> list[i];
        
        if ((list[i] >= 1 && list[i] <= N) && (able_number.find(list[i]) != able_number.end()))
            able_number.erase(list[i]);
        else
            cost += (i + 1);
    }

    cout << cost << '\n';

    return 0;
}