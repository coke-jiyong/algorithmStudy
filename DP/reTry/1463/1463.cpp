#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> DP(N + 1);
    for (int i = 2; i <= N; i++)
    {
        DP[i] = DP[i - 1] + 1;
        if (DP[i] % 2 == 0)
            DP[i] = min({DP[i], DP[i / 2] + 1});
        if (DP[i] % 3 == 0)
            DP[i] = min({DP[i], DP[i / 3] + 1});
    }
    cout << DP[N] << endl;
    return 0;
}