#include <iostream>
#include <cmath>

using namespace std;

void pita(int a, int b, int c)
{
    if (a - (b + c) == 0)
        cout << "right" << '\n';
    else
        cout << "wrong" << '\n';
}

int main()
{
    while (true)
    {
        int A, B, C;
        cin >> A >> B >> C;

        if (A == 0 && B == 0 && C == 0)
            break;

        A = pow(A, 2);
        B = pow(B, 2);
        C = pow(C, 2);

        //cout << A << " " << B << " " << C;

        if (A > B)
        {
            if (A > C)
                pita(A, B, C);
            else
                pita(C, A, B);
        }
        else if (B > C)
            pita(B, A, C);
        else
            pita(C, B, A);
    }
    return 0;
}
