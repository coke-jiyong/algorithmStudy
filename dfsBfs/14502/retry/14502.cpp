#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int row, col;
int originMap[9][9];
bool visited[9][9];
vector<pair<int, int>> blankV;
pair<int, int> way[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 위 오 아 왼
void input()
{
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> originMap[i][j];
            if (originMap[i][j] == 0)
                blankV.push_back({i, j});
        }
    }
}
int get_safety_zone(pair<int, int> wall1, pair<int, int> wall2, pair<int, int> wall3)
{
    int copiedMap[9][9];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            copiedMap[i][j] = originMap[i][j];

    queue<pair<int, int>> Q;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (copiedMap[i][j] == 2)
            {
                Q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    copiedMap[wall1.first][wall1.second] = 1;
    copiedMap[wall2.first][wall2.second] = 1;
    copiedMap[wall3.first][wall3.second] = 1;

    while (!Q.empty())
    {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextRow = r + way[i].first;
            int nextCol = c + way[i].second;
            if (nextRow < 0 || nextCol < 0 || nextRow >= row || nextCol >= col)
                continue;
            if (copiedMap[nextRow][nextCol] == 0 && !visited[nextRow][nextCol])
            {
                Q.push({nextRow, nextCol});
                copiedMap[nextRow][nextCol] = 2;
                visited[nextRow][nextCol] = true;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (copiedMap[i][j] == 0)
                result++;
    return result;
}
void sol()
{
    int len = blankV.size();
    int maxSaftyZone = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            for (int k = j + 1; k < len; k++)
            {
                int answer = get_safety_zone(blankV[i], blankV[j], blankV[k]);
                maxSaftyZone = maxSaftyZone < answer ? answer : maxSaftyZone;
            }
        }
    }

    cout << maxSaftyZone << endl;
}
int main(void)
{
    input();
    sol();
    return 0;
}