// #include <iostream>
// #include <vector>
// using namespace std;

// int students[100001];
// bool visited[100001];
// int dfs(int n)
// {
//     visited[n] = true;
//     if (visited[students[n]])
//         return students[n];
//     else
//         return dfs(students[n]);
// }
// int main(void)
// {
//     int T;
//     cin >> T;
//     for (int i = 0; i < T; i++)
//     {
//         int n;
//         cin >> n;
//         int cnt = 0;
//         for (int j = 1; j <= n; j++)
//             cin >> students[j];

//         for (int k = 1; k <= n; k++)
//         {
//             int a = dfs(k);
//             if (k == a)
//                 cnt++;
//             fill(visited, visited + 100001, false);
//         }
//         cout << n - cnt << endl;
//         fill(students, students + 100001, false);
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

int students[100001];
bool visited[100001];
bool finished[100001];
int cnt;

void dfs(int node)
{
    visited[node] = true;
    int next = students[node];
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> students[i];
            visited[i] = false;
            finished[i] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
                dfs(i);
        }

        cout << n - cnt << '\n'; // 팀을 이루지 못한 학생 수 출력
    }
    return 0;
}
