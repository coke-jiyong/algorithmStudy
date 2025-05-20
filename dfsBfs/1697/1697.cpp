#include <iostream>
#include <queue>

using namespace std;
int N, K;
bool visited[100001];

void input(void)
{
    cin >> N >> K;
}
void sol(int n, int second)
{
    int way[2] = {1, -1};
    queue<pair<int, int>> q;
    q.push({n, second});
    visited[n] = true;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        if (t.first == K)
        {
            cout << t.second << endl;
            return;
        }
        for (int i = 0; i < 2; i++)
        {
            int next = t.first + way[i];
            if (next < 0 || next > 100000)
                continue;
            if (!visited[next])
            {
                visited[next] = true;
                q.push({next, t.second + 1});
            }
        }
        int next = t.first * 2;
        if (next < 0 || next > 100000)
            continue;
        if (!visited[next])
        {
            visited[next] = true;
            q.push({next, t.second + 1});
        }
    }
}
int main(void)
{
    input();
    sol(N, 0);
    return 0;
}