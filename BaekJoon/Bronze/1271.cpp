//못품

#include <iostream>
#include <cstring>

using namespace std;

char* max(char* a, char* b)
{
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] < b[i]) return b;
        else return a;
    }
    return a;
}

void sub(char* a, char* b)
{
    for (int i = 0; i < strlen(b); i++)
    {
        a[i] = a[i] - b[i] + '0';
        if (a[i] < '0')
        {
            a[i] += 10;
            a[i-1]--;
        }
    }
}

void divSub(char* n, char* m, char* q, int i)
{
    q[i] = '0';
    while (n[i-1] > '0' || max(n + i, m) == n + i)
    {
        sub(n + i, m);
        ++q[i];
    }
}


void div(char* n, char* m, char* q)
{
    int i = 0;
    int len = strlen(n) - strlen(m);

    while (i <= len)
        divSub(n,m,q,i++);
    q[i] = '\0';
}

int main()
{
    char n[1001], m[1001], q[1001];
    cin >> n >> m;
    div(n,m,q);

    int qo = 0, no = 0;
    while (q[qo] == '0')
        qo++;
    while(n[no] == '0')
        no++;

    if (q[0] == '\0')
    {
        q[0] = '0';
        q[1] = '\0';
    }

    if (n[no] == '\0') no--;
    if (q[qo] == '\0') qo--;

    cout << q + qo << '\n';
    cout << n + no << '\n';

    return 0;
}