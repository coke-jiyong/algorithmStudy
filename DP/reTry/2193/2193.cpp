#include <iostream>
#include <vector>
using namespace std;

long long DP[91];
int main(void)
{
    int N;
    cin >> N;

    DP[1] = 1;
    DP[2] = 1;
    for (int o = 3; o <= N; o++)
        DP[o] = DP[o - 1] + DP[o - 2];

    cout << DP[N] << endl;
    return 0;
}