#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 2; i * i <= N; i++)
    {
        while (N % i == 0)
        {
            cout << i << '\n';
            N /= i;
        }
    }
    if (N > 1) // 남은 마지막 소수
        cout << N << '\n';

    return 0;
}
