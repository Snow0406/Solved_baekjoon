#include <iostream>

using namespace std;

int list[1000001];
int main ()
{
    long long min, max;
    cin >> min >> max;

    long long result = max - min + 1;
    for (long long i = 2; i * i <= max; i++)
    {
        long long q = min / ( i * i );
        if (min % ( i * i) != 0)
            q++;

        while(q * (i*i) <= max)
        {
            if(!list[q * (i * i) - min])
            {
                list[q * (i * i) - min] = true;
                result--;
            }
            q++;
        }
    }

    cout << result << "\n";
    
    return 0;
}