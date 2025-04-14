#include <iostream>
#include <vector>

using namespace std;
int sticker[2][100001];
int DP[2][100001];
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int main(void)
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < n; k++)
                cin >> sticker[j][k];
        DP[0][0] = sticker[0][0];
        DP[1][0] = sticker[1][0];
        DP[0][1] = sticker[1][0] + sticker[0][1];
        DP[1][1] = sticker[0][0] + sticker[1][1];
        for (int k = 2; k < n; k++)
        {
            DP[0][k] = MAX(DP[1][k - 1], DP[1][k - 2]) + sticker[0][k];
            DP[1][k] = MAX(DP[0][k - 1], DP[0][k - 2]) + sticker[1][k];
        }

        for (int z = 0; z < 2; z++)
        {
            for (int x = 0; x < n; x++)
            {
                cout << DP[z][x] << ' ';
            }
            cout << endl;
        }

        cout << MAX(DP[0][n - 1], DP[1][n - 1]) << endl;
    }
    return 0;
}