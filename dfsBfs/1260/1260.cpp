#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[1001];
vector<int> graph[1001];
void dfs(int n)
{
    cout << n << ' ';
    visited[n] = true;
    for (int i = 0; i < graph[n].size(); i++)
        if (!visited[graph[n][i]])
            dfs(graph[n][i]);
}
void bfs(int n)
{
    queue<int> q;
    q.push(n);
    visited[n] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int i = 0; i < graph[x].size(); i++)
        {
            int a = graph[x][i];
            if (!visited[a])
            {
                q.push(a);
                visited[a] = true;
            }
        }
    }
}
int main(void)
{
    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int graphNum, data;
        cin >> graphNum >> data;
        graph[graphNum].push_back(data);
        graph[data].push_back(graphNum); // 양뱡향
    }
    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());
    dfs(V);
    cout << '\n';
    fill(visited, visited + 1001, false);
    bfs(V);
    cout << '\n';
    return 0;
}