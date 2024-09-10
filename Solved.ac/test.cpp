#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> T(N);
    for(int i = 0; i < N; i++) {
        cin >> T[i];
    }
    
    vector<int> dp_odd(N, 1);  // 홀수 위치에서 끝나는 최장 부분 수열의 길이
    vector<int> dp_even(N, 1); // 짝수 위치에서 끝나는 최장 부분 수열의 길이
    
    int max_length = 1;
    
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(i % 2 == 1) { // 홀수 위치
                if(T[i] > T[j]) {
                    dp_odd[i] = max(dp_odd[i], dp_even[j] + 1);
                }
            } else { // 짝수 위치
                if(T[i] < T[j]) {
                    dp_even[i] = max(dp_even[i], dp_odd[j] + 1);
                }
            }
        }
        max_length = max({max_length, dp_odd[i], dp_even[i]});
    }
    
    cout << max_length << endl;
    
    return 0;
}