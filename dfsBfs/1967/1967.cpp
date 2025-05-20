#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> v[10001];
bool visited[10001];
int n;

int farthestData = 0;
int farthestDist = 0;
void dfs(int data, int dist)
{
    if (visited[data])
        return;
    visited[data] = true;

    if (farthestDist < dist)
    {
        farthestData = data;
        farthestDist = dist;
    }

    for (auto &next : v[data])
    {
        int nextData = next.first;
        int nextDist = next.second;

        dfs(nextData, dist + nextDist);
    }
}
void sol()
{
    dfs(1, 0);
    farthestDist = 0;
    memset(visited, false, sizeof(visited));
    dfs(farthestData, 0);
    cout << farthestDist << endl;
}
void input()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int p, c, d;
        cin >> p >> c >> d;
        v[p].push_back({c, d});
        v[c].push_back({p, d}); // 양방향
    }
}
int main(void)
{
    input();
    sol();
    return 0;
}