#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 1 = 1^   1
// 2 = 1^+1^   2
// 3 = 1^+1^+1^ 3
// 4 = 2^   1
// 5 = 2^ + 1^  2
// 6 = 2^ + 1^ + 1^ 3
// 7 = 2^ + 1^ + 1^ + 1^    4
// 8 = 2^ + 2^  2
// 9 = 3^
// 10 = 3^ + 1^
// 11 = 3^ + 1^ + 1^
// 12 = 3^ + 1^ + 1^ + 1^
// 13 = 3^ + 2^
// 14 = 3^ + 2^ + 1^
// 15 = 3^ + 2^ + 1^ + 1^
// 14 = 4^
int dp[100001];
int main(void)
{
    int N;
    cin >> N; // 7
    for (int i = 1; i <= N; i++)
    {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }

    cout << dp[N] << endl;
    return 0;
}