#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, P, X = 0, flag = 0;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> P;
        if(P > 1) flag++;
        X ^= P;
    }
    /*
     * flag를 하는 이유는 돌 더미가 1보다 클때는 선택이 다양해서 XOR의 합이 0일때 cubelover 승리
     * 다만 돌 더미의 크기가 1일때는 XOR의 합이 1일때만 cubelover 승리
     *
     * [2, 2] (flag && !x 일때)
     * 
     * 1. koosaga 차례:
     *   - [2, 2] -> [1, 2] 또는 [0, 2]
     *
     * 2. cubelover 차례:
     * - [1, 2] -> [1, 1] 또는 [1, 0]
     * - [0, 2] -> [0, 1] 또는 [0, 0]
     *
     * 따라서 cubelover 승리
     */
    if (flag && X == 0 || !flag && X == 1)
        cout << "cubelover" << "\n";
    else
        cout << "koosaga" << "\n";

    return 0;
}