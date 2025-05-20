#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> v[101];
bool visited[101];
void input()
{
    cin >> N; // 노드
    cin >> M; // 간선
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}
int cnt = 0;
void dfs(int n)
{
    if (visited[n])
        return;
    visited[n] = true;
    cnt++;
    for (auto &next : v[n])
        dfs(next);
}

int main(void)
{
    input();
    dfs(1);
    cout << cnt - 1 << endl;
    return 0;
}