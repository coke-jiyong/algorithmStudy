#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        vector<long long> padoban(3, 1);
        for (int i = 3; i < N; i++)
            padoban.push_back(padoban[i - 2] + padoban[i - 3]);
        cout << padoban[N - 1] << endl;
    }
    return 0;
}