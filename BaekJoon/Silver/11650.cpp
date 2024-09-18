#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
  int x;
  int y;
};

bool compare(node a, node b)
{
    if (a.x == b.x) //x 좌표가 같으면
        return a.y < b.y; //b의 y 좌표가 더 큰걸로 잘렬
    else //x 좌표가 같지 않다면
        return a.x < b.x; //b의 x 좌표가 더 큰걸로 정렬
}

int main() {

    int N;
    cin >> N;

    vector<node> list(N);
    for (int i = 0; i < N; i++)
        cin >> list[i].x >> list[i].y;

    sort(list.begin(), list.end(), compare);

    for (int i = 0; i < N; i++)
        cout << list[i].x << " " << list[i].y << '\n';
    

 return 0;
}