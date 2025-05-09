#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[25][25];
bool visited[25][25]; //     ↑       →       ↓       ←
pair<int, int> way[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int cnt;
int N;
void dfs(int i, int j)
{
    visited[i][j] = true;       // 방문한 노드 visited 등록
    for (int o = 0; o < 4; o++) // 동서남북 방향 확인
    {
        int row = i + way[o].first;  // 행 연산
        int col = j + way[o].second; // 열 연산

        if (row < 0 || row >= N || col < 0 || col >= N) // 버퍼 오버플로우 방지
            continue;

        if (map[row][col] == 1 && !visited[row][col]) // 동서남북 방향 중 집이 존재하고, 방문하지 않은 인덱스면 cnt + 1 후 재귀호출
        {
            cnt++;
            dfs(row, col);
        }
    }
}

int main()
{
    vector<int> answer;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str; // 입력 주의, 정수로 입력받아봤지만 안됨 : 정수로 입력받으려면 0 1 1 0 이런식으로 스페이스 한칸이 필요 함
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
            if (!visited[i][j] && map[i][j] == 1) // 모든 인덱스를 탐색하며 방문하지 않았고, 집이 있다면 cnt 1 로 초기화 후 재귀 시작
            {
                cnt = 1;
                dfs(i, j);
                // cout << cnt << endl;
                answer.push_back(cnt);
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for (auto &i : answer)
        cout << i << endl;
    return 0;
}
