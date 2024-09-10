#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N;
    cin >> N;
    
    vector<string> nowJob(N);
    for (int i = 0; i < N; i++)
        cin >> nowJob[i];

    int K;
    cin >> K;

    vector<string> userJob(K);
    for (int i = 0; i < K; i++)
        cin >> userJob[i];

    vector<string> newJob;
    for(auto j: nowJob)
    {
        //출처 : https://9x211x2.tistory.com/17
        if (find(userJob.begin(), userJob.end(), j) == userJob.end())
        {
            newJob.push_back(j);
        }
    }

    cout << newJob.size() << "\n";
    for (auto j : newJob) cout << j << "\n";
    
    return 0;
}