#include <iostream>
#include <vector>
using namespace std;
long long DP[1001][10];
#define MOD 10007
int main(void)
{
    int N;
    cin >> N;

    for (int i = 0; i < 10; i++)
        DP[1][i] = 1;

    for (int i = 2; i <= N; i++)
    {
        DP[i][0] = 1;
        for (int j = 1; j < 10; j++)
            DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % MOD;
    }

    long long sum = 0;
    for (int i = 0; i < 10; i++)
        sum += DP[N][i];
    cout << sum % MOD << endl;
    return 0;
}