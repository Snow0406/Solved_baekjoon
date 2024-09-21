#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;

    int a = A * (B % 10);
    int b = A * ((B % 100) / 10);
    int c = A * ((B % 1000) / 100);
    
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    cout << a + (b*10) + (c*100) << "\n";
    
    return 0;
}