#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * PI 배열 구하기
 * PI[i] = 패턴의 0~i 부분 문자열에서 접두사와 접미사가 일치하는 최대 길이
 * 예: "ABABA" -> PI = [0, 0, 1, 2, 3]
 */
vector<int> getPI(const string &pattern)
{
    const int n = pattern.length();
    vector<int> pi(n, 0);
    int j = 0; // 현잭까지 일치한 접두사의 길이

    // i=1부터 시작하는 이유:
    // pi[0]은 정의상 항상 0 (길이 1인 문자열은 접두사와 접미사가 없음)
    for (int i = 1; i < n; i++)
    {
        // 불일치 발생시 이전 pi 값을 이용해 j 되돌리기
        // 이미 획인한 부분 재활용하여 효율성 확보
        while (j > 0 && pattern[i] != pattern[j]) j = pi[j - 1];

        // 일치하는 경우: 접두사 길이 증가
        if (pattern[i] == pattern[j]) pi[i] = ++j;
    }
    return pi;
}


// 시간 복잡도 기존 O(N*M)인데 KMP는 O(N+M)
vector<int> KMP(const string &text, const string &pattern)
{
    vector<int> result;
    vector<int> pi = getPI(pattern);

    const int n = text.length();
    const int m = pattern.length();
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        while (j > 0 && text[i] != pattern[j]) j = pi[j-1];

        if (text[i] == pattern[j]) j++;

        if (j == m)
        {
            result.push_back(i - m + 1);

            // 겹치는 패턴이 있을 수 있으므로 처음부터 시작하지 않고 pi 배열을 이용해 적절한 위치로 이동
            j = pi[j-1];
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string T, P;
    getline(cin, T);
    getline(cin, P);

    const auto &result = KMP(T, P);

    cout << result.size() << endl;
    for (const int i : result)
    {
        cout << i + 1 << " ";
    }

    return 0;
}
