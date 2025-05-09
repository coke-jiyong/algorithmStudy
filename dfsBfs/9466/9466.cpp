#include <iostream>
#include <vector>
using namespace std;

/*
2
7
[1][2][3][4][5][6][7]
 3  1  3  7  3  4  6   ----------> 3
8
[1][2][3][4][5][6][7][8]
 1  2  3  4  5  6  7  8 ----------> 0

[1]->3
[3]->3 --> cycle!
[2]->1 visited.
[3]->3 visited.
[4]->7
[7]->6
[6]->4 --> cycle!

 */
int students[100001];
bool visited[100001];
bool done[100001];
int cnt;

void dfs(int n)
{
    visited[n] = true;
    int next = students[n];
    if (!visited[next])
        dfs(next);
    else if (!done[next]) // 사이클 발견 현재 n=6 next=4
    {
        for (int i = students[next]; i != next; i = students[i])
            cnt++; // i가 7일때 +1 , 6일때 +1, 4일때 종료
        cnt++;     // next 자기자신 ++
    }
    done[n] = true;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            cin >> students[j];
            visited[j] = false;
            done[j] = false;
        }
        for (int k = 1; k <= n; k++)
            if (!visited[k])
                dfs(k);
        cout << n - cnt << endl;
    }
    return 0;
}
