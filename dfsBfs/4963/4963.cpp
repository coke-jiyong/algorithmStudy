#include <iostream>
using namespace std;
bool map[51][51];
bool visited[51][51];
int w, h, answer;
//                          ↑        →       ↓       ←        ↗       ↙       ↖       ↘
pair<int, int> way[8] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
void input()
{
    cin >> w >> h; // 1~50
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> map[i][j];
            visited[i][j] = false;
        }
    }
}
void dfs(int row, int col)
{
    visited[row][col] = true;
    for (int i = 0; i < 8; i++)
    {
        int newRow = row + way[i].first;
        int newCol = col + way[i].second;

        if (newRow < 0 || newCol < 0 || newRow >= h || newCol >= w)
            continue;
        if (!visited[newRow][newCol] && map[newRow][newCol])
            dfs(newRow, newCol);
    }
}
void solution()
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (!visited[i][j] && map[i][j])
            {
                dfs(i, j);
                answer++;
            }
        }
    }
}
int main(void)
{
    while (1)
    {
        answer = 0;
        input();
        if (w == 0 && h == 0)
            break;
        solution();
        cout << answer << endl;
    }
    return 0;
}
