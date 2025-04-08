#include <iostream>

using namespace std;
//[자릿수][마지막 숫자일때 경우의 수]
// ex [2][2] -> 두 자리수 이면서 끝이 2 인 계단수의 갯수

int main(void)
{

    int N;
    cin >> N;
    long long DP[N + 1][10] = {0};
    long long sum = 0;
    // for (int i = 0; i < 10; i++) 길이가 1이면서 0으로 끝나는 계단수는 없다. -> 0으로 시작하는 수는 계단수가 아니다.
    // {
    //     DP[1][i] = 1;
    // }

    for (int i = 1; i < 10; i++)
        DP[1][i] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                DP[i][j] = DP[i - 1][j + 1] % 10000000000;
            else if (j == 9)
                DP[i][j] = DP[i - 1][j - 1] % 10000000000;
            else
                DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j + 1] % 10000000000;
        }
    }

    for (int i = 0; i < 10; i++)
        // sum += DP[i][j] % 1000000000; 모두 더할 필요가 없었음. DP[N] 의 원소들만 더하면 됨 .
        sum += DP[N][i];

    cout << sum % 1000000000 << endl;
    return 0;
}