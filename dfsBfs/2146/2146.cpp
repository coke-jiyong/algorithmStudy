#include <iostream>
#include <queue>
#include <cstring>
#include <set>
#include <tuple>
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
        bool is_edge = false;
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
            else if (ground[newR][newC] == 0 && is_edge == false)
                is_edge = true;
        }
        if (is_edge)
            edges.insert({row, col});
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

int bfs_from_edge()
{
    memset(visited, false, sizeof(visited));
    queue<tuple<int, int, int, int>> q;
    for (auto &i : edges)
        q.push({i.first, i.second, 0, ground[i.first][i.second]});
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        int r = get<0>(t);
        int c = get<1>(t);

        for (int i = 0; i < 4; i++)
        {
            int newR = r + way[i].first;
            int newC = c + way[i].second;
            if (newR < 0 || newC < 0 || newR >= N || newC >= N)
                continue;
            if (ground[newR][newC] != 0 && ground[newR][newC] != get<3>(t))
                return get<2>(t);
            if (!visited[newR][newC] && ground[newR][newC] == 0)
            {
                q.push({newR, newC, get<2>(t) + 1, ground[newR][newC]});
                visited[newR][newC] = true;
            }
        }
    }
    return -1;
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
    int res = bfs_from_edge();
    cout << res << endl;
}

int main(void)
{
    input();

    solution();

    print();

    return 0;
}
