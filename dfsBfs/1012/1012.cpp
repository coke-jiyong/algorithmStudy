#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
pair<int, int> way[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 위오아왼
bool visited[51][51];
int ground[51][51];
int M, N, K;
void sol(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int newX = x + way[i].first;
        int newY = y + way[i].second;
        if (newX < 0 || newY < 0 || newX >= N || newY >= M)
            continue;
        if (!visited[newX][newY] && ground[newX][newY])
            sol(newX, newY);
    }
}
void input()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> M >> N >> K;
        int answer = 0;
        memset(ground, false, sizeof(ground));
        for (int i = 0; i < K; i++)
        {
            int x, y; // (y,x)
            cin >> y >> x;
            ground[x][y] = true;
        }
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!visited[i][j] && ground[i][j])
                {
                    sol(i, j);
                    answer++;
                }
            }
        }
        cout << answer << endl;
    }
}

int main(void)
{
    input();
    return 0;
}