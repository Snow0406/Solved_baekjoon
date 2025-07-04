#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int arr[100] = { 0, };
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int sum = 0, num = 0;
    for (int x = 0; x < N-2; x++)
    {
        for (int y = x + 1; y < N-1; y++)
        {
            for (int z = y + 1; z < N; z++)
            {
                sum = arr[x] + arr[y] + arr[z];
                if (sum <= M && sum > num)
                    num = sum;
            } 
        }
    }

    cout << num << endl;

    return 0;
}