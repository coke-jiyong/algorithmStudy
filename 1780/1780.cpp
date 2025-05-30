#include <iostream>
#include <vector>
using namespace std;
int arr[10]; // [0] -> -1 개수 , [1]-> 0개수, [2]->1개수
int main(void)
{
    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> v[i][j];

    // 0~2   3~5     6~8
    // 0~2   0~2     0~2

    // 0~2   3~5     6~8
    // 3~5   3~5     3~5

    // 0~2   3~5     6~8
    // 6~8   6~8     6~8

    for (int row = 0; row < N; row += 3)
    {
        for (int col = 0; col < N; col += 3)
        {
            int base = v[row][col];
            bool f = false;
            for (int i = row; i < row + 3; i++)
                for (int j = col; j < col + 3; j++)
                    if (base != v[i][j])
                        f = true;

            if (!f)
                arr[base + 1]++;
            else
            {
                for (int i = row; i < row + 3; i++)
                    for (int j = col; j < col + 3; j++)
                        arr[v[i][j] + 1]++;
            }
        }
    }
    for (int i = 0; i < 3; i++)
        cout << arr[i] << endl;

    return 0;
}
