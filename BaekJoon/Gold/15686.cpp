// 출처 : https://velog.io/@dianestar/백준BOJ-15686번-치킨배달

#include <iostream>
#include <limits.h>
#include <vector>
#include <cmath>

using namespace std;

struct House
{
    int r, c;
};

struct Chicken
{
    int r, c;
    bool isVisited;
};

int N, M;
int minDistance = INT_MAX;
vector<House> house;
vector<Chicken> chicken;

void calculateDistance ()
{
    int chickenDistance = 0;
    for (int i = 0; i < house.size(); i++)
    {
        int minHouseDistance = INT_MAX;
        for (int j = 0; j < chicken.size(); j++)
        {
            if (!chicken[j].isVisited) continue;
            int houseDistance = abs(house[i].r - chicken[j].r) + abs(house[i].c - chicken[j].c);
            if (houseDistance < minHouseDistance)
            {
                minHouseDistance = houseDistance;
            }
        }
        chickenDistance += minHouseDistance;
    }
    if (chickenDistance < minDistance)
        minDistance = chickenDistance;
}

void selectChicken(int index, int count)
{
    if (count == M)
        calculateDistance();

    for (int i = index; i < chicken.size(); i++)
    {
        if (chicken[i].isVisited) continue;
        chicken[i].isVisited = true;
        selectChicken(i, count + 1);
        chicken[i].isVisited = false;
    }
}

int main ()
{
    cin >> N >> M;

    int map;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map;
            if (map == 1)
                house.push_back({i, j});
            else if (map == 2)
                chicken.push_back({i, j, false});
        }
    }

    selectChicken(0, 0);
    cout << minDistance << "\n";
    
    return 0;
}