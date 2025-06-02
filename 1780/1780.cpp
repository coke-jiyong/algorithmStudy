#include <iostream>
#include <vector>
using namespace std;
int arr[2188][2188];
int paper[3];
int N;
void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
}

void sol(int n, pair<int, int> pos) // 3 6,6
{
    int row = pos.first;
    int col = pos.second;
    int base = arr[row][col];
    bool f = false;

    for (int i = row; i < row + n; i++)
        for (int j = col; j < col + n; j++)
            if (base != arr[i][j])
                f = true;
    if (!f)
    {
        paper[base + 1]++;
        return;
    }

    int next = n / 3;
    if (next == 1)
    {
        for (int i = row; i < row + n; i += next)
            for (int j = col; j < col + n; j += next)
                paper[arr[i][j] + 1]++;

        return;
    }

    for (int i = row; i < row + n; i += next)
        for (int j = col; j < col + n; j += next)
            sol(next, {i, j});
}
int main(void)
{
    input();
    sol(N, {0, 0});
    for (int i = 0; i < 3; i++)
        cout << paper[i] << endl;
    return 0;
}
