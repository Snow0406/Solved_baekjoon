#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int X, Y, R;
    cin >> X >> Y >> R;

    int count = 0;

    // 북, 동, 남, 서
    const int dx[4] = { -1, 0, 1, 0 };
    const int dy[4] = { 0, 1, 0, -1 };

    vector<vector<int>> map(N, vector<int>(M, 0));
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    while (true)
    {
        if (map[X][Y] == 0) //청소를 안 했으면
        {
            count++;
            map[X][Y] = 2;
        }

        bool cleanAble = false;

        for (int i = 0; i < 4; i++)
        {
            R = (R + 3) % 4;
            int next_X = X + dx[R];
            int next_Y = Y + dy[R];
            if (map[next_X][next_Y] == 0)
            {
                X = next_X;
                Y = next_Y;
                cleanAble = true;
                break;
            }
        }

        if (!cleanAble)
        {
            int back = (R + 2) % 4; //북이면 남, 남이면 북, 동이면 서, 서이면 동
            int next_X = X + dx[back], next_Y = Y + dy[back];
            if (map[next_X][next_Y] == 1) break;
            X = next_X;
            Y = next_Y;
        }
    }

    cout << count << endl;

    return 0;
}

/*
 *    0
 * 3     1
 *    2
 */