#include <iostream>
using namespace std;
int map[25][25];
bool visited[25][25];
pair<int, int> way[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 위오아왼
int cnt;
int N;
void dfs(int i, int j)
{
    visited[i][j] = true;
    for (int o = 0; o < 4; o++) // 위오아왼 확인
    {
        int row = i + way[o].first;
        int col = j + way[o].second;
        if (row < 0 || row >= N || col < 0 || col >= N)
            continue;

        if (map[row][col] == 1 && !visited[row][col])
        {
            cnt++;
            dfs(row, col);
        }
    }
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == '1')
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && map[i][j] == 1)
            {
                cnt = 1;
                dfs(i, j);
                cout << cnt << endl;
            }
        }
    }
    return 0;
}
