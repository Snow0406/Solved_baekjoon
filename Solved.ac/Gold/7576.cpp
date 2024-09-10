#include <iostream>
#include <queue>

using namespace std;

struct loc
{
    int x, y;
};

int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };

int n, k, c;
int box[1001][1001];
queue<loc> qt;

bool isInBox(const int x, const int y)
{
    return (0 <= x && x < n && 0 <= y && y < k);
}

void bfs()
{
    while (!qt.empty())
    {
        const int x = qt.front().x;
        const int y = qt.front().y;
        qt.pop();

        for (int i = 0; i < 4; ++i)
        {
            const int dx = x + xx[i];
            const int dy = y + yy[i];

            if(!isInBox(dx,dy) || box[dy][dx] != 0) continue;
            
            box[dy][dx] = box[y][x]+1;
            qt.push({dx, dy});
            
        }
    }
};

int main()
{
    cin >> n >> k;
    
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            cin >> box[i][j];
            if(box[i][j] == 1) qt.push({j, i});
        }
    }

    bfs();

    int m = 0;
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++)
        {
            if(box[i][j] == 0)
            {
                cout << -1 << "\n";
                return 0;
            }
            if(m < box[i][j]) m = box[i][j];
        }
    }

    cout << m-1 << "\n";
    return 0;
}
