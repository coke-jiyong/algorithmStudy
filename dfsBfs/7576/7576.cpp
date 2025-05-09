#include <iostream>
#include <queue>
using namespace std;
int M, N;
//                          ↑        →       ↓       ←
pair<int, int> way[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int box[1001][1001];
queue<pair<int, int>> q;
void input()
{
    cin >> M >> N; // 2 ~ 1000
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
                q.push({i, j});
        }
    }
}
void bfs()
{
    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();
        int r = pos.first;
        int c = pos.second;
        for (int i = 0; i < 4; i++)
        {
            int newR = r + way[i].first;
            int newC = c + way[i].second;
            if (newR < 0 || newC < 0 || newR >= N || newC >= M)
                continue;
            if (box[newR][newC] == 0)
            {
                box[newR][newC] = box[r][c] + 1;
                q.push({newR, newC});
            }
        }
    }
}
void solution()
{
    bfs();
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (box[i][j] == 0)
            {
                cout << -1 << endl;
                return;
            }
            max = max < box[i][j] ? box[i][j] : max;
        }
    }
    cout << max - 1 << endl;
}
int main(void)
{
    input();
    solution();
    return 0;
}

/*
6 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1

6 4
1 -1 0 0 0 0
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1

1 -1 0 0 0 0
1 -1 0 0 0 0
0 0 0 0 -1 1
0 0 0 0 -1 1

1 -1 0 0 0 0
1 -1 0 0 0 1
1 0 0 0 -1 1
0 0 0 0 -1 1

1 -1 0 0 0 1
1 -1 0 0 1 1
1 1 0 0 -1 1
1 0 0 0 -1 1

1 -1 0 0 1 1
1 -1 0 1 1 1
1 1 1 0 -1 1
1 1 0 0 -1 1

1 -1 0 1 1 1
1 -1 0 1 1 1
1 1 1 1 -1 1
1 1 1 0 -1 1

1 -1 1 1 1 1
1 -1 1 1 1 1
1 1 1 1 -1 1
1 1 1 1 -1 1
*/