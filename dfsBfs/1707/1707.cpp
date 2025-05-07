#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define BLACK 1
#define RED 2

vector<int> graph[20001];
int visited[20001];

void dfs(int n)
{
    if (visited[n] == 0)
        visited[n] = RED;
    for (int i = 0; i < graph[n].size(); i++)
    {
        if (visited[graph[n][i]] == 0)
        {
            visited[graph[n][i]] = visited[n] == RED ? BLACK : RED;
            dfs(graph[n][i]);
        }
    }
}
void bfs(int n)
{
    queue<int> q;
    q.push(n);
    visited[n] = RED;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        // cout << x << ' ';
        for (int i = 0; i < graph[x].size(); i++)
        {
            int a = graph[x][i];
            if (!visited[a])
            {
                q.push(a);
                visited[a] = visited[x] == RED ? BLACK : RED;
            }
        }
    }
}
bool is_bipartitegraph(int V)
{
    for (int i = 1; i <= V; i++)
        for (int j = 0; j < graph[i].size(); j++)
            if (visited[i] == visited[graph[i][j]])
                return false;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int V, E;
        cin >> V >> E;
        for (int j = 0; j < E; j++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int j = 1; j <= V; j++)
            if (!visited[j])
                bfs(j);
        // dfs(j);

        if (is_bipartitegraph(V))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

        // clear
        for (int j = 1; j <= V; j++)
            graph[j].clear();
        // fill(graph[j].begin(), graph[j].end(), 0); 모두 0 으로 초기화 하지만 그래프의 크기는 그대로 남아있음.
        fill(visited, visited + 20001, 0);
    }
    return 0;
}