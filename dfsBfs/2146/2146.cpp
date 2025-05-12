#include <iostream>
#include <queue>
#include <cstring>
#include <set>
using namespace std;

//                          ↑        →       ↓       ←
pair<int, int> way[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// 각 섬마다 번호붙인 후 가장자리 큐에 삽입
int ground[101][101];
bool visited[101][101];
set<pair<int, int>> edges;

int N;
void input()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> ground[i][j];
}
void name_tag_land(int r, int c, int tag)
{
    ground[r][c] = tag;
    queue<pair<int, int>> q;
    q.push({r, c});

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        visited[row][col] = true;
        for (int i = 0; i < 4; i++)
        {
            int newR = row + way[i].first;
            int newC = col + way[i].second;
            if (newR < 0 || newC < 0 || newR >= N || newC >= N)
                continue;
            if (!visited[newR][newC] && ground[newR][newC] == 1)
            {
                q.push({newR, newC});
                ground[newR][newC] = tag;
            }
            else if (ground[newR][newC] == 0)
                edges.insert({row, col});
        }
    }
}
void print()
{
    cout << "ground : " << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << ground[i][j] << ' ';
        cout << "\n";
    }
    cout << "edges : " << endl;
    for (auto &i : edges)
        cout << i.first << "," << i.second << endl;
}
int bfs(int row, int col)
{
    int landTag = ground[row][col];
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newR = r + way[i].first;
            int newC = c + way[i].second;
            if (newR < 0 || newC < 0 || newR >= N || newC >= N)
                continue;
            if (ground[newR][newC] != 0 && ground[newR][newC] != landTag)
                return cnt;
            if (!visited[newR][newC] && ground[newR][newC] == 0)
                q.push({newR, newC});
        }
        cnt++;
    }
    return cnt;
}
void solution()
{
    int tag = 2;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && ground[i][j] == 1)
            {
                name_tag_land(i, j, tag++);
            }
        }
    }

    // cout << bfs(2, 1) << endl;
    //  int min = INT32_MAX;
    //  for (auto &i : edges)
    //  {
    //      int res = bfs(i.first, i.second);
    //      min = min > res ? res : min;
    //  }
}

int main(void)
{
    input();

    solution();

    print();

    for (auto &i : edges)
    {
        int res = bfs(i.first, i.second);
        cout << "edge{" << i.first << "," << i.second << "} : " << res << endl;
    }
    return 0;
}
