#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[1001];
vector<int> graph[1001];
void dfs(int n)
{
    visited[n] = true;
    for (int i = 0; i < graph[n].size(); i++)
        if (!visited[graph[n][i]])
            dfs(graph[n][i]);
}
int main(void)
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 양뱡향
    }
    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            ++answer;
            dfs(i);
        }
    }
    cout << answer << '\n';
    return 0;
}