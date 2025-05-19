#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int V;
vector<pair<int, int>> v[100001];
bool visited[100001];
void input()
{
    cin >> V;
    for (int i = 0; i < V; i++)
    {
        int j;
        cin >> j;
        while (1)
        {
            int node, weight;
            cin >> node;
            if (node == -1)
                break;
            cin >> weight;
            v[j].push_back({node, weight});
            v[node].push_back({j, weight});
        }
    }
}
int cnt = 0;
int dfs(int n)
{
    visited[n] = true;
    if (v[n].size() == 1)
    {
        if (!visited[v[n][0].first])
        {
            cnt += v[n][0].second;
            dfs(v[n][0].first);
        }
    }
    else
    {
        int max = 0;
        for (auto &i : v[n])
            if (!visited[i.first])
                max = max < i.second ? i.second : max;
    }
}

// sizeof(visited)
void sol()
{
    for (int i = 1; i <= V; i++)
    {
    }
}
/*
5
1 3 2 -1
2 4 4 -1
3 1 2 4 3 -1
4 2 4 3 3 5 6 -1
5 4 6 -1
*/
int main(void)
{
    input();
    return 0;
}