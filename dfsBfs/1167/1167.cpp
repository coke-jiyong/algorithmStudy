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
        }
    }
}
int maxDist = 0;
int farNode = 0;
void dfs(int node, int weight)
{
    if (visited[node])
        return;
    visited[node] = true;
    if (weight > maxDist)
    {
        farNode = node;
        maxDist = weight;
    }

    for (auto &i : v[node])
    {
        int nextNode = i.first;
        int nextWeight = i.second;
        dfs(nextNode, nextWeight + weight);
    }
}

// sizeof(visited)
void sol()
{
    // 임의의 노드A에서 가장 먼 노드B를 구함.
    // 구한 노드B에서 가장 먼 노드C를 구함
    // B~C의 거리가 트리의 지름
    dfs(2, 0);
    maxDist = 0;
    memset(visited, false, sizeof(visited));
    dfs(farNode, 0);
    cout << maxDist << endl;
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
    sol();
    return 0;
}