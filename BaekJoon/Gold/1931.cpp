/*
 *  Problem: 1931
 *  Rank: Gold 5
 *  Algorithm: 그리디 알고리즘, 정렬
 * ====================================
 *  어떤 기준으로 회의를 선택할 건가?
 *  1. 시작 시간이 빠른 순서
 *  2. 회의 시간이 짧은 순서 (중간에 끼어있는 
 *  3. 끝나는 시간이 빠른 순서
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.second == b.second) // 끝나는 시간이 같으면 시작시간이 빠른것부터
            return a.first < b.first;
        return a.second < b.second; // 끝나는 시간이 빠른것부터
    });
/*
    (1,4)
    (3,5)
    (0,6)
    (5,7)
    (3,8)
    (5,9)
    (6,10)
    (8,11)
    (8,12)
    (2,13)
    (12,14)
*/

    int count = 0;
    int lastEndTime = 0;
    for (int i = 0; i < N; i++)
    {
        if (v[i].first >= lastEndTime)
        {
            count++;
            lastEndTime = v[i].second;
        }
    }

    cout << count;
    return 0;
}