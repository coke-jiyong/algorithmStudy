#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[1001];
bool visited[1001];

void dfs(int n)
{
    visited[n] = true;
    if (!visited[graph[n][0]])
        dfs(graph[n][0]);
}
int main(void)
{
    int T;
    cin >> T;
    for (int o = 0; o < T; o++)
    {
        int N;
        int cnt = 0;
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            int n;
            cin >> n;
            graph[i].push_back(n);
        }
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                dfs(i);
                cnt++;
            }
        }
        cout << cnt << endl;

        for (int i = 1; i <= N; i++)
            graph[i].clear();
        fill(visited, visited + N + 1, false);
    }
    return 0;
}