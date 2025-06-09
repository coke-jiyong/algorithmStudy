#include <iostream>
using namespace std;
int N, M, K;
void input()
{
    cin >> N >> M >> K;
}

void sol()
{
    int answer = 0;
    while (N >= 2 && M >= 1 && N - 2 + M - 1 >= K)
    {
        N -= 2;
        M -= 1;
        answer++;
    }

    cout << answer << endl;
}

int main(void)
{
    input();
    sol();
    return 0;
}