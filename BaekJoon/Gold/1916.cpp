#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

//출처 : https://youngtoad.tistory.com/22

using namespace std;

int N, M, start, _end, a, b, c;
vector<pair<int, int>> map[1001];
int list[1001];

void busSearch()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (cost > list[here]) continue;

        for (int i = 0; i < map[here].size(); i++)
        {
            int next = map[here][i].first;
            int next_cost = map[here][i].second;

            if (list[next] > list[here] + next_cost) {
                list[next] = list[here] + next_cost;
                pq.emplace(list[next], next);
            }
        }
    }
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        map[a].emplace_back(b, c);
    }
    
    cin >> start >> _end;
    fill(list, list + N + 1, INT_MAX);
    list[start] = 0;
    busSearch();

    cout << list[_end];
    return 0;
}
