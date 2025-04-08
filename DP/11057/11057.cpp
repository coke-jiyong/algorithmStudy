#include <iostream>
using namespace std;
// 오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이때, 인접한 수가 같아도 오름차순으로 친다.
// 예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.
// 수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다

// 첫째 줄에 N (1 ≤ N ≤ 1,000)이 주어진다.
// 첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 나눈 나머지를 출력한다.

// 1  --> 10
// 2 --> 55
// 3 --> 220

//[길이][마지막 수]
const int MOD = 10007;
int main(void)
{
    int N;
    cin >> N;

    long long arr[N + 1][10] = {0};
    long long sum = 0;
    for (int i = 0; i < 10; i++)
        arr[1][i] = 1;

    for (int i = 2; i <= N; i++)
    {
        arr[i][0] = 1;
        for (int j = 1; j < 10; j++)
        {
            arr[i][j] = (arr[i][j - 1] + arr[i - 1][j]) % MOD;
        }
    }

    for (int i = 0; i < 10; i++)
        sum += arr[N][i];

    cout << sum % MOD << endl;
    return 0;
}