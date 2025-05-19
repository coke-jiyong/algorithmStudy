#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> v[100001];
bool visited[100001];
int answer[100001];
void input()
{
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void dfs(int n)
{
    visited[n] = true;
    for (auto &i : v[n])
    {
        if (!visited[i])
        {
            visited[i] = true;
            answer[i] = n;
            dfs(i);
        }
    }
}
void sol()
{
    for (int i = 1; i <= N; i++)
        if (!visited[i])
            dfs(i);

    for (int i = 2; i <= N; i++)
        cout << answer[i] << '\n';
}
int main(void)
{
    input();
    sol();
    return 0;
}
/*
7
1 6
6 3
3 5
4 1
2 4
4 7


*/
