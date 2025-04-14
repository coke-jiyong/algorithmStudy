#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000000
/*
길이 1 = [0~N-1] = 1
길이 2 = [2][0]:1 [2][1]:1
길이 3 = 0:1 ,
길이 4 =  1210,1010,3210,
*/

long long DP[101][10];
int main(void)
{
    int N;
    cin >> N;

    for (int i = 1; i < 10; i++)
        DP[1][i] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                DP[i][j] = DP[i - 1][1] % MOD;
            else if (j == 9)
                DP[i][j] = DP[i - 1][8] % MOD;
            else
                DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % MOD;
        }
    }
    long long sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += DP[N][i];
    }

    cout << sum % MOD << endl;
    return 0;
}