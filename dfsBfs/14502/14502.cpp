#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
// 모든 빈 공간 3개를 벽으로 바꾸는 경우의수에서 bfs실행(바이러스퍼뜨리기) , 안전구역출력
int max(int a, int b) { return a < b ? b : a; }
pair<int, int> way[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int N, M;
int map[9][9];                // 원본
vector<pair<int, int>> blank; // 빈 공간의 좌표들
bool visited[9][9];

void input(void)
{
    cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
                blank.push_back({i, j}); // 원본 맵 빈 공간
        }
    }
}

int bfs(pair<int, int> wall1, pair<int, int> wall2, pair<int, int> wall3)
{
    int copyMap[N][M];
    //    memcpy(copyMap, map, N * M * sizeof(int)); // sizeof()까먹어서 쓰레기값 찾는데 한참걸림 . . . 집중하자
    //    ㄴ 이 구문도 오류. 동적계산은 틀리지않았지만 2차원배열은 이렇게하면 오류 발생가능성 있음.

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            copyMap[i][j] = map[i][j];

    copyMap[wall1.first][wall1.second] = 1;
    copyMap[wall2.first][wall2.second] = 1;
    copyMap[wall3.first][wall3.second] = 1;

    // bfs진행
    queue<pair<int, int>> virus;
    memset(visited, false, sizeof(visited)); // visited[N][M] (동적배열) 썼다가 에러 못찾음 .. 쓰지말자 . . .
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (copyMap[i][j] == 2)
            {
                virus.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!virus.empty())
    {
        int x = virus.front().first;
        int y = virus.front().second;
        virus.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextX = x + way[i].first;
            int nextY = y + way[i].second;
            if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M)
                continue;

            if (!visited[nextX][nextY] && copyMap[nextX][nextY] == 0)
            {
                copyMap[nextX][nextY] = 2;
                virus.push({nextX, nextY});
                visited[nextX][nextY] = true;
            }
        }
    }

    int saftyZone = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (copyMap[i][j] == 0)
                saftyZone++;
    return saftyZone;
}
void sol()
{
    int answer = 0;
    for (int i = 0; i < blank.size(); i++)
        for (int j = i + 1; j < blank.size(); j++)
            for (int k = j + 1; k < blank.size(); k++)
                answer = max(bfs(blank[i], blank[j], blank[k]), answer);
    // answer = MAX(bfs(blank[i], blank[j], blank[k]), answer); // 와 이런 버그 처음 bfs가 두번 호출됨. -> answer = ((bfs(...) < answer) ? answer : bfs(...));
    cout << answer << endl;
}

int main(void)
{
    input();
    sol();
    return 0;
}