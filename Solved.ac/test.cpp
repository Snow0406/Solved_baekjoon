#include <iostream>
#include <vector>
<<<<<<< Updated upstream
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
=======
#include <queue>

using namespace std;

struct Train {
    int to;
    long long start, end;
    Train(int t, long long s, long long e) : to(t), start(s), end(e) {}
};

struct State {
    int station;
    long long time;
    State(int s, long long t) : station(s), time(t) {}
    bool operator>(const State s) const {
        return time > s.time;
    }
};

const long long MAX = 1e18;
vector<vector<Train>> graph;
int N, M, K, Q;

long long train_sim(int startStation, long long startTime) {
    vector<long long> list(N + 1, MAX);
    priority_queue<State, vector<State>, greater<>> pq;
    
    list[startStation] = startTime;
    pq.emplace(startStation, startTime);
    
    while (!pq.empty()) {
        const State current = pq.top();
        pq.pop();
        
        if (current.station == K) return current.time;
        if (current.time > list[current.station]) continue;
        
        for (const Train& train : graph[current.station]) {
            if (current.time <= train.start && train.end < list[train.to]) {
                list[train.to] = train.end;
                pq.emplace(train.to, train.end);
            }
        }
    }
    
    return -1;
}

int main() {
    //외부 소스 : https://kimcoder.tistory.com/49
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K >> Q;
    graph.resize(N + 1);
    
    for (int i = 0; i < M; i++) {
        int s, d;
        long long ts, td;
        cin >> s >> ts >> d >> td;
        graph[s].emplace_back(d, ts, td);
    }
    
    for (int i = 0; i < Q; i++) {
        int s;
        long long t;
        cin >> s >> t;
        const long long result = train_sim(s, t);
        cout << result << '\n';
    }
>>>>>>> Stashed changes
    
    return 0;
}