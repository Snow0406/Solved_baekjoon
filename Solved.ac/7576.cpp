#include <iostream>
#include <queue>

using namespace std;

struct loc
{
    int x, y;
};

int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };

int a, b, c;
int box[1001][1001];
queue<loc> qt;

bool isInBox(const int x, const int y)
{
    return (0 <= x && x < a && 0 <= y && y < b);
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
    cin >> a >> b;
    
    for(int i=0; i<b; i++){
        for(int j=0; j<a; j++){
            cin >> box[i][j];
            if(box[i][j] == 1) qt.push({j, i});
        }
    }

    bfs();

    int m = 0;
    for(int i=0; i<b; i++){
        for(int j=0; j<a; j++)
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
