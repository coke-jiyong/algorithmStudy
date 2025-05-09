#include <iostream>
#include <queue>
using namespace std;
int N, M; // 2~100
bool visited[101][101];
int maze[101][101];
queue<pair<int, int>> q;
//                          ↑        →       ↓       ←
pair<int, int> way[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == '1')
                maze[i][j] = 1;
            else
                maze[i][j] = 0;
        }
    }
}

void bfs()
{
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        visited[r][c] = true;
        for (int i = 0; i < 4; i++)
        {
            int newR = r + way[i].first;
            int newC = c + way[i].second;
            if (newR < 0 || newC < 0 || newR >= N || newC >= M)
                continue;
            if (maze[newR][newC] == 1 && !visited[newR][newC])
            {
                maze[newR][newC] += maze[r][c];
                q.push({newR, newC});
            }
        }
    }
}
int main(void)
{
    input();
    q.push({0, 0});
    bfs();
    cout << maze[N - 1][M - 1] << endl;
    return 0;
}