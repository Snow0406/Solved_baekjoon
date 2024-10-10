#include <iostream>

using namespace std;

int main ()
{
    int num, asc = 0, desc = 0;
    for (int i = 0; i < 8; i++)
    {
        cin >> num;
        if (num == i+1) asc++;
        else if (num == 8-i) desc++;
    }

    if (asc == 8) cout << "ascending" << "\n";
    else if (desc == 8) cout << "descending" << "\n";
    else cout << "mixed" << "\n";
    
    return 0;
}