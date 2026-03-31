#include <stdio.h>

#define MAX_N 101
#define MAX_L 10001
#define MAX_BODY 10001

int board[MAX_N][MAX_N]; // 1: 사과, 2: 뱀

int dx[] = { 0, 1, 0, -1};
int dy[] = { 1, 0, -1, 0};

int queue_x[MAX_BODY];
int queue_y[MAX_BODY];
int turn[MAX_L]; // -1: L, 1: D

int front = 0, rear = 0;

void add_back(int x, int y) {
    rear = (rear + 1) % MAX_BODY;
    queue_x[rear] = x;
    queue_y[rear] = y;
}

void delete_front(int* x, int* y) {
    front = (front + 1) % MAX_BODY;
    *x = queue_x[front];
    *y = queue_y[front];
}

int main() {
    int n, k, l;
    scanf("%d", &n);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        board[x][y] = 1;
    }
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        if (c == 'L') turn[x] = -1;
        else turn[x] = 1;
    }
    
    int now_x = 1, now_y = 1;
    int time = 0;
    int dir = 0;
    
    board[1][1] = 2;
    add_back(1, 1);
    while (1) {
        time++;
        
        int new_x = now_x + dx[dir];
        int new_y = now_y + dy[dir];
        
        if (new_x < 1 || new_x > n || new_y < 1 || new_y > n) break;
        if (board[new_x][new_y] == 2) break;
        
        now_x = new_x;
        now_y = new_y;
        add_back(now_x, now_y);
        
        if (board[now_x][now_y] == 1) {
            board[now_x][now_y] = 2;
        } else {
            board[now_x][now_y] = 2;
            int tx, ty;
            delete_front(&tx, &ty);
            board[tx][ty] = 0;
        }
        
        if (turn[time] == -1) {
            dir = (dir - 1 + 4) % 4;   // 왼쪽 회전
        } else if (turn[time] == 1) {
            dir = (dir + 1) % 4;   // 오른쪽 회전
        }
    }
    
    printf("%d", time);
}

