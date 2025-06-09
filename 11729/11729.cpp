#include <iostream>
#include <vector>
using namespace std;
int N;
int cnt;
void input()
{
    cin >> N;
}

void hanoi(int n, char from, char via, char to)
{
    cout << "current cnt: " << ++cnt << endl;
    if (n == 1)
    {
        cout << from << ' ' << to << endl;
        return;
    }

    hanoi(n - 1, from, to, via);
    cout << from << ' ' << to << endl;
    hanoi(n - 1, via, from, to);
}

int main(void)
{
    input();
    int cnt = 1;
    for (int i = 0; i < N; i++)
        cnt *= 2;
    cnt -= 1;

    cout << cnt << endl;

    hanoi(N, '1', '2', '3');
    return 0;
}