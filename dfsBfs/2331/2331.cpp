#include <iostream>
#include <cmath>
using namespace std;
#define MAX 236197 // A 9999 P 5 -> 9^5*4 에서 +1 해줘야 함... 인덱스가 236196 인 visited[236196] 를 사용할 수도 있기때문.
int visited[MAX];
int P;
void dfs(int n)
{
    if (visited[n] == 2)
        return;

    visited[n]++;
    int sum = 0;
    while (n != 0)
    {
        int i = n % 10;
        sum += pow(i, P);
        n /= 10;
    }
    dfs(sum);
}

int main(void)
{
    int A;
    cin >> A >> P;
    dfs(A);
    int cnt = 0;
    for (int i = 0; i < MAX; i++)
        if (visited[i] == 1)
            cnt++;
    cout << cnt << '\n';
    return 0;
}