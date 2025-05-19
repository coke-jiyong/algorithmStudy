#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
//                          ↑        →       ↓       ←
pair<int, int> way[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// 각 섬마다 번호붙인 후 가장자리 큐에 삽입
int ground[101][101];
bool visited[101][101];
vector<pair<int, int>> edges[100001]; // 섬의 태그는 101을 초과 할 수 있음 . .. .
int N;
typedef struct info
{
    int row;
    int col;
    int cnt;
} INFO;
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
            edges[tag].push_back({row, col});
    }
}
int bfs_from_edge(int tag)
{
    memset(visited, false, sizeof(visited));
    queue<INFO> q;
    // 0 = edgesRow , 1 = edgesCol , 2 = count
    for (auto &i : edges[tag])
    {
        q.push(INFO{i.first, i.second, 0});
        visited[i.first][i.second] = true; // 시작점도 방문처리! 집중하자
    }

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        int r = t.row;
        int c = t.col;
        for (int i = 0; i < 4; i++)
        {
            int newR = r + way[i].first;
            int newC = c + way[i].second;
            if (newR < 0 || newC < 0 || newR >= N || newC >= N)
                continue;

            if (ground[newR][newC] != 0 && ground[newR][newC] != tag)
                return t.cnt;

            if (!visited[newR][newC] && ground[newR][newC] == 0)
            {
                q.push(INFO{newR, newC, t.cnt + 1}); // 현재 섬의 태그를 갱신시키지말고 그대로 넣어줘야 함.
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
    int res = 1e9;
    for (int i = 2; i < tag; i++)
        res = MIN(res, bfs_from_edge(i));

    cout << res << endl;
}
int main(void)
{
    input();

    solution();

    return 0;
}
