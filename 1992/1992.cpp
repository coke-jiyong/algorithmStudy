#include <iostream>
using namespace std;
int N;
int arr[65][65];
void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++)
            arr[i][j] = str[j] - '0';
    }
}

void sol(int n, pair<int, int> startPos)
{
    int row = startPos.first;
    int col = startPos.second;
    int base = arr[row][col];

    bool is_same = true;
    for (int i = row; i < row + n; i++)
    {
        for (int j = col; j < col + n; j++)
        {
            if (base != arr[i][j])
            {
                is_same = false;
                break;
            }
        }
        if (!is_same)
            break;
    }

    if (is_same)
    {
        cout << base;
        return;
    }

    int next = n / 2;

    cout << '(';
    for (int i = row; i < row + n; i += next)
        for (int j = col; j < col + n; j += next)
            sol(next, {i, j});
    cout << ')';
}
int main(void)
{
    input();
    // debug();
    sol(N, {0, 0});
    cout << endl;
    return 0;
}