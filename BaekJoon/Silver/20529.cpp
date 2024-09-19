#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int getDistance(string a, string b) {
    int distance = 0;
    for (int i = 0; i < 4; i++)
        if (a[i] != b[i]) distance++;
    return distance;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        vector<string> list;
        for (int j = 0; j < N; j++)
        {
            string str;
            cin >> str;
            list.push_back(str);
        }
        
       /*
        * 비둘기집 원리
        * 
        * MBTI 종류가 16개 있는데 16*2 (32)개 가 있으면 MBTI 중복 2개씩 있는건데
        * 33개부터 중복된 MBTI가 3개가 되는거다. 따라서 중복된 MBTI가 3개니깐
        * 가장 가까운 세 학생 사이의 심리적인 거리를 구하는거니 답은 0
        *
        */
        if (N > 32)
        {
            cout << 0 << "\n";
            continue;
        }
        
        int result = 20;
        for (int j = 0; j < N-2; j++) {
            for (int k = j + 1; k < N-1; k++) {
                for (int l = k + 1; l < N; l++) {
                    result = min(result, getDistance(list[j], list[k]) + getDistance(list[k], list[l]) + getDistance(list[l], list[j]));
                }
            }
        }
        cout << result << "\n";
    }
    
    return 0;
}