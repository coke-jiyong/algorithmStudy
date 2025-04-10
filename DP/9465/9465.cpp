#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫째 줄에는 n (1 ≤ n ≤ 100,000)이 주어진다.
// 다음 두 줄에는 n개의 정수가 주어지며, 각 정수는 그 위치에 해당하는 스티커의 점수이다.
// 연속하는 두 정수 사이에는 빈 칸이 하나 있다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

// 각 테스트 케이스 마다, 2n개의 스티커 중에서 두 변을 공유하지 않는 스티커 점수의 최댓값을 출력한다.

int main(void)
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    { // test case
        int n;
        cin >> n;
        vector<vector<int>> row(2);
        for (int j = 0; j < 2; j++)
        {
            vector<int> col(n);
            for (int i = 0; i < n; i++)
                cin >> col[i];

            row[j] = col;
        }

        vector<vector<int>> DP(2, vector<int>(n));
        DP[0][0] = row[0][0];
        DP[1][0] = row[1][0];
        DP[0][1] = row[1][0] + row[0][1];
        DP[1][1] = row[0][0] + row[1][1];

        for (int i = 2; i < n; i++)
        {
            DP[0][i] = max({DP[1][i - 1], DP[1][i - 2]}) + row[0][i];
            DP[1][i] = max({DP[0][i - 1], DP[0][i - 2]}) + row[1][i];
        }
        cout << max({DP[0][n - 1], DP[1][n - 1]}) << endl;
    }

    return 0;
}