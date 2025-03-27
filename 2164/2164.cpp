#include <iostream>
#include <queue>
// 1~N 카드번호 , 1번카드가 제일 위, N 번카드가 제일 아래인상태로 놓여있음. 1<=N<=500,000
// 1. 제일위에있는카드를 바닥에 버림.
// 2. 그 후 제일 위에있는카드를 제일 아래에있는 카드 밑으로 옮김.
// 3. 제일 마지막에 남게되는 카드를 구해야함

using namespace std;
int main(void)
{

    queue<int> q;
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    while (q.size() != 1)
    {
        q.pop();
        int i = q.front();
        q.pop();
        q.push(i);
    }

    cout << q.front() << endl;
    return 0;
}