#include <iostream>
#include <queue>

using namespace std;

struct loc
{
    int x, y, z;
};

int xx[6] = { 0,0,0,0,-1,1 };
int yy[6] = { 0,0,-1,1,0,0 };
int zz[6] = { -1,1,0,0,0,0 };

int n, k, c;
int box[101][101][101];
queue<loc> qt;

bool isInBox(const int x, const int y, const int z)
{
    return (0 <= x && x < n && 0 <= y && y < k && 0 <= z && z < c);
}

void bfs()
{
    while (!qt.empty())
    {
        const int x = qt.front().x;
        const int y = qt.front().y;
        const int z = qt.front().z;
        qt.pop();

        for (int i = 0; i < 6; ++i)
        {
            const int dx = x + xx[i];
            const int dy = y + yy[i];
            const int dz = z + zz[i];

            if(!isInBox(dx,dy,dz) || box[dz][dy][dx] != 0) continue;
            
            box[dz][dy][dx] = box[z][y][x]+1;
            qt.push({dx, dy, dz});
            
        }
    }
};

int main()
{
    cin >> n >> k >> c;

    for (int i= 0; i < c; i++)
    {
        for(int j=0; j<k; j++)
        {
            for(int k=0; k<n; k++)
            {
                cin >> box[i][j][k];
                if(box[i][j][k] == 1) qt.push({k,j,i});
            }
        }   
    }

    bfs();

    int m = 0;
    for (int i= 0; i < c; i++)
    {
        for(int j=0; j<k; j++)
        {
            for(int k=0; k<n; k++)
            {
                if(box[i][j][k] == 0)
                {
                    cout << -1 << "\n";
                    return 0;
                }
                if(m < box[i][j][k]) m = box[i][j][k];
            }
        }   
    }

    cout << m-1 << "\n";
    return 0;
}

